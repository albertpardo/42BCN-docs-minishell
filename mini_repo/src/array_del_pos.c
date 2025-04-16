/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_del_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:26:07 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:07:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/*
 *	Generate a new array of strings without the string in arr[pos]
 *
 *	Don't check of arr == NULL
 */

char	**rmposarr(char **arr, int pos)
{
	int		i;
	char	**new_arr;

	i = 0;
	new_arr = (char **) malloc(sizeof(char **) * (sizearr(arr)));
	if (new_arr != NULL)
	{
		cp_except_pos(new_arr, arr, pos);
		free(arr[pos]);
		free(arr);
	}
	else
		error_msg_exit(ERROR_MALLOC);
	return (new_arr);
}
