/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:29:31 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 16:31:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	ft_isspecialchar(int c)
{
	return (c == '#' || c == '@' || c == '*' || c == ' ' || c == '$');
}

/*	Generate a partial duplicate of the string "s1" with "n" size
 *	if n > length(s1), returns duplicate of "s1"					*/
char	*ft_strdupsize(char *s1, size_t n)
{
	char	*new_str;

	if (s1 == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strdup("\0"));
	if (n > ft_strlen(s1))
		return (ft_strdup(s1));
	new_str = ft_calloc(sizeof(char), n + 1);
	if (new_str != NULL)
		return (ft_memcpy(new_str, s1, n));
	return (NULL);
}

/*	new_str is deleted and assigned to the new one */
/*	*new_str is deleted and replaced for *new_str joined with *tmp */
void	my_strjoin(char **new_str, char **tmp)
{
	char	*tmp2;

	tmp2 = ft_strjoin(*new_str, *tmp);
	if (tmp2 == NULL)
		error_exit(ERROR_MALLOC);
	free(*new_str);
	*new_str = tmp2;
	free(*tmp);
	*tmp = NULL;
}

/*
 * Duplicate chars from 'src[start]' with 'size = i - start' to 'new_str'  
 * i : is '$' position
 */
void	my_srcdupsize(int i, int start, char *src, char **dst)
{
	char	*tmp;

	if (src[start] != '\0')
	{
		tmp = ft_strdupsize(&src[start], i - start);
		if (tmp == NULL)
			error_exit(ERROR_MALLOC);
		my_strjoin(dst, &tmp);
	}
}

int	dollar_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			i = avoid_simplequotes(i, str);
		if (str[i] != '\0')
		{
			if (str[i] == '$')
				count++;
			i++;
		}
	}
	return (count);
}
