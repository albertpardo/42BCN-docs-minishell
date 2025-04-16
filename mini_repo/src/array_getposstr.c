/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_getposstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:38:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/22 10:39:19 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * returns the numbers of chars in 'str' until 'c'
 *  str must be not NULL
 *  
 */

static int	ft_strlentoc(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] != '\0' || c == '\0')
		return (i);
	return (-1);
}

/*
 * Returns 
 * 	- the position 'i' in '**arr' where 'substr is found
 * 	or
 * -1 if 'str' is not found
 */

int	getposstr(char **arr, char *substr)
{
	int		i;
	int		substrlen;
	int		strarrlen;
	int		found;

	found = 0;
	i = 0;
	substrlen = ft_strlen(substr);
	while (found == 0 && arr[i] != NULL)
	{
		if (ft_strchr(arr[i], '=') != NULL)
			strarrlen = ft_strlentoc(arr[i], '=');
		else
			strarrlen = ft_strlen(arr[i]);
		if (substrlen == strarrlen && \
				ft_strncmp(arr[i], substr, substrlen) == 0)
			found = 1;
		else
			i++;
	}
	if (found == 1)
		return (i);
	return (-1);
}
