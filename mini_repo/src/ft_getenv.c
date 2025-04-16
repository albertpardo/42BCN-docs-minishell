/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:23:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:19:34 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * if 'substr' is found 'arr' 
 * 	returns the rest of str from pos last char in 'substr'+1
 * else returns NULL
 */

#include "minishell.h"
#include "executor.h"

char	*ft_getenv(char **arr, char *substr)
{
	int		pospath;
	char	*str;
	int		substrlen;

	str = NULL;
	pospath = getposstr(arr, substr);
	if (pospath != -1)
	{
		substrlen = ft_strlen(substr);
		if (arr[pospath][substrlen] != '\0' && arr[pospath][substrlen] == '=')
			substrlen++;
		str = ft_strdup(&arr[pospath][substrlen]);
		if (str == NULL)
			error_msg_exit(ERROR_MALLOC);
	}
	return (str);
}
