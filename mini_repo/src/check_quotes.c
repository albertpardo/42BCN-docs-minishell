/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:23:04 by spereyra          #+#    #+#             */
/*   Updated: 2024/04/30 11:46:35 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_closing_quote(char *input, int i, int *qt_cnt, char qt)
{
	int	j;

	j = i + 1;
	(*qt_cnt)++;
	while (input[j] && input[j] != qt)
		j++;
	if (input[j] == qt)
		(*qt_cnt)++;
	return (j - i);
}

int	check_quotes(t_shell *shell)
{
	int	len;
	int	i;
	int	sq_cnt;
	int	dq_cnt;

	sq_cnt = 0;
	dq_cnt = 0;
	len = ft_strlen(shell->input);
	i = 0;
	while (i < len)
	{
		if (shell->input[i] == '\"')
			i = i + find_closing_quote(shell->input, i, &dq_cnt, '\"');
		if (shell->input[i] == '\'')
			i = i + find_closing_quote(shell->input, i, &sq_cnt, '\'');
		i++;
	}
	if ((dq_cnt > 0 && dq_cnt % 2 != 0) || (sq_cnt > 0 && sq_cnt % 2 != 0))
	{
		printf("minishell: there are unclosed quotes!\n");
		shell->exit_st = 1;
		return (0);
	}
	return (1);
}
/* Original OK
int	check_quotes(char *input)
{
	int	len;
	int	i;
	int	sq_cnt;
	int	dq_cnt;

	sq_cnt = 0;
	dq_cnt = 0;
	len = ft_strlen(input);
	i = 0;
	while (i < len)
	{
		if (input[i] == '\"')
			i = i + find_closing_quote(input, i, &dq_cnt, '\"');
		if (input[i] == '\'')
			i = i + find_closing_quote(input, i, &sq_cnt, '\'');
		i++;
	}
	if ((dq_cnt > 0 && dq_cnt % 2 != 0) || (sq_cnt > 0 && sq_cnt % 2 != 0))
	{
		printf("minishell there are unclosed quotes!\n");
		return (0);
	}
	return (1);
}*/

int	len_unquoted(char *str)
{
	int	len;
	int	newlen;
	int	i;

	len = ft_strlen(str);
	newlen = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] != '\'' && str[i] != '\"')
			newlen++;
		else if (str[i] == '\'')
		{
			while (str[++i] != '\'')
				newlen++;
		}
		else if (str[i] == '\"')
		{
			while (str[++i] != '\"')
				newlen++;
		}
		i++;
	}
	return (newlen);
}

void	strcopy_unquoted(char *dst, char *src, int dst_len, int src_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < src_len && j < dst_len)
	{
		if (src[i] != '\'' && src[i] != '\"')
			dst[j++] = src[i];
		else if (src[i] == '\'')
		{
			while (src[++i] != '\'')
				dst[j++] = src[i];
		}
		else if (src[i] == '\"')
		{
			while (src[++i] != '\"')
				dst[j++] = src[i];
		}
		i++;
	}
	dst[j] = '\0';
}

char	*strdup_unquoted(char *str)
{
	int		len;
	int		newlen;
	char	*newstr;

	newstr = 0;
	len = ft_strlen(str);
	newlen = len_unquoted(str);
	newstr = malloc((newlen + 1) * sizeof(char));
	if (!newstr)
		return (0);
	strcopy_unquoted(newstr, str, newlen, len);
	return (newstr);
}
