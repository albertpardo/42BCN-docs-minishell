/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_shlvl_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:41 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:20:34 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

#define SHLVL_EQUAL "SHLVL="
#define SHLVL_CERO "SHLVL=0"
#define SHLVL_ONE "SHLVL=1"

/*
 *  Set SHLVL=num   where num is the right value
 */

static void	set_shlvl(int num, int pos_shlvl, char **env)
{
	char	*str;
	char	*str_tmp;

	str_tmp = ft_itoa(num);
	if (str_tmp != NULL)
	{
		str = ft_strjoin(SHLVL_EQUAL, str_tmp);
		if (str != NULL)
			change_value_pos(env, pos_shlvl, str);
		else
			error_exit(ERROR_MALLOC);
		free(str_tmp);
	}
	else
		error_exit(ERROR_MALLOC);
}

void	manager_shlvl_number(char *shlvl, int pos_shlvl, char **env)
{
	int		num;

	num = ft_atoi((const char *)shlvl);
	num++;
	if (num < 0)
		change_set_shlvl_dup(SHLVL_CERO, pos_shlvl, env);
	else if (num > -1 && num < 1000)
		set_shlvl(num, pos_shlvl, env);
	else if (num == 1000)
		change_set_shlvl_dup(SHLVL_EQUAL, pos_shlvl, env);
	else
	{
		change_set_shlvl_dup(SHLVL_ONE, pos_shlvl, env);
		ft_putstr_fd("minishell: warning: shell level (", 2);
		ft_putnbr_fd(num, 2);
		ft_putendl_fd(") too high, resetting to 1", 2);
	}
}

int	isstrnum(char *str)
{
	while (str != NULL && *str != '\0' && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

void	change_set_shlvl_dup(char *strshlvl, int pos_shlvl, char **env)
{
	char	*str;

	str = ft_strdup(strshlvl);
	if (str != NULL)
		change_value_pos(env, pos_shlvl, str);
	else
		error_msg_exit(ERROR_MALLOC);
}

void	add_set_shlvl_dup(char *strshlvl, char ***env)
{
	char	*str;

	str = ft_strdup(strshlvl);
	if (str != NULL)
		add_new_var(env, str);
	else
		error_msg_exit(ERROR_MALLOC);
}
