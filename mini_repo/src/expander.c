/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:26:38 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 16:51:56 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "expander.h"

/*
 * Expands "$?"
 */
static void	expand_last_exit(int *i, char *str, t_expandata *expandt, int val)
{
	char	*tmp;

	my_srcdupsize(*i, expandt->start, str, &(expandt->new_str));
	*i += 2;
	expandt->start = *i;
	tmp = ft_itoa(val);
	if (tmp == NULL)
		error_msg_exit(ERROR_MALLOC);
	my_strjoin(&(expandt->new_str), &tmp);
}

/*	Expands a $VARIABLE from Environment
 *
 *	var is get with 'getenv'
 *	TODO:
 *	- Optimizar numero argumentos
 *	- Usar copia ENVIRONMENT
 *
 * Arguments
 *  i : position of $. After expands contains next position is 'str' to evaluate
 *  start: fist position on 'str' to join to 'new_str'
 *  new_str : portion if 'str' when join the new expand.
 *
 * Variables
 *	j : use as position in 'str'
 *	tmp1 : temporal Varname
 *	tmp2 : temporal Varvalue
 */

static void	expand_env_var(int *i, char *str, t_expandata *expandt, char **env)
{
	int		j;
	char	*var_env;
	char	*tmp1;

	my_srcdupsize(*i, expandt->start, str, &(expandt->new_str));
	j = *i + 1;
	while (ft_isalnum(str[j]) || str[j] == '_')
		j++;
	tmp1 = ft_strdupsize(&str[*i + 1], j - (*i + 1));
	if (tmp1 == NULL)
		error_msg_exit(ERROR_MALLOC);
	var_env = ft_getenv(env, tmp1);
	if (var_env == NULL)
	{
		var_env = ft_strdup("");
		if (var_env == NULL)
			error_msg_exit(ERROR_MALLOC);
	}
	free(tmp1);
	my_strjoin(&(expandt->new_str), &var_env);
	*i = j;
	expandt->start = *i;
}

/* DOLLAR EXPANDER
 * For the rigth '$' format the variable is expanded
 *
 * if 'str' has simple quotes . this function expect pairs simple quotes
 *
 * Cases :
 * - "..$"  or  "..."
 * - ".$5." or ".$ ." or ".$$." or ".$#." or ".$@." or ".$*."
 * - "...$?..."
 * - "...$Aa.." or "...$_a.." environment var
 * - Message if condition is not on previous cases
 *
 *'i' is used as position in 'str'
 */

static void	make_expand(int *i, char *str, t_expandata *expandt, t_shell *shell)
{
	if (str[*i] != '$' || (str[*i] == '$' && str[*i + 1] == '\0'))
		(*i)++;
	else if (str[*i] == '$' && \
			(ft_isdigit(str[*i + 1]) || ft_isspecialchar(str[*i + 1])))
		*i += 2;
	else if (str[*i] == '$' && str[*i + 1] == '?')
		expand_last_exit(i, str, expandt, shell->exit_st);
	else if (str[*i] == '$' && \
		(ft_isalpha(str[*i + 1]) || str[*i + 1] == '_'))
		expand_env_var(i, str, expandt, shell->envp_exec);
	else
		(*i)++;
}

char	*dollar_expand(char *str, t_shell *shell)
{
	int			i;
	t_expandata	expandata;

	i = 0;
	expandata.start = 0;
	expandata.new_str = ft_strdup("");
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			i = avoid_simplequotes(i, str);
		if (str[i] != '\0')
			make_expand(&i, str, &expandata, shell);
	}
	my_srcdupsize(i, expandata.start, str, &(expandata.new_str));
	return (expandata.new_str);
}

/* Checks the token_lst of the shell, before the parser stage.
 * If a token has a word with at least one dollar, the word is expanded
 */

void	expander(t_shell *shell)
{
	char	*new_word;
	t_token	*cur_token;

	cur_token = shell->token_lst;
	while (cur_token != NULL)
	{
		if (cur_token->word != 0 && dollar_counter(cur_token->word) > 0 \
				&& (cur_token->prev == 0 || (cur_token->prev != 0 \
						&& cur_token->prev->oper != LESS_LESS)))
		{
			new_word = dollar_expand(cur_token->word, shell);
			free(cur_token->word);
			cur_token->word = new_word;
		}
		cur_token = cur_token->next;
	}
}
