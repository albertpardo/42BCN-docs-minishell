/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:46:43 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:12:32 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/*
 * Returns number of 'str' in 'arr'
 */

int	sizearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

/*
 * Free strings from **arr  and free arr
 */

void	free_arr_content(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

/*
 * copy all str from 'ori' to 'dest' except the string in pos
 * sizeof(dest) = sizeof(ori) - 1
 *
 */

void	cp_except_pos(char **dest, char **ori, int pos)
{
	int	i;
	int	size;

	i = 0;
	while (i < pos)
	{
		dest[i] = ori[i];
		i++;
	}
	i++;
	size = sizearr(ori);
	while (i <= size)
	{
		dest[i -1] = ori[i];
		i++;
	}
}

/*
 *  Copies 'n_elements' from 'ori' to 'dest'
 *
 *  Where sizeof(dest) >= n_elements
 *	and dest[n_elements] is put to NULL
 */

void	cp_arr(char **dest, char **ori, int n_elem)
{
	int	i;

	i = -1;
	while (++i < n_elem)
		dest[i] = ori[i];
	dest[n_elem] = NULL;
}

/*
 * generate a new array of strings  adding 'str' at the end of 'arr'.
 * Each 'str' is realocated on the 'new_arr'
 * 'str' is not necesary to free because no copy is made
 *
 * 'arr' is deleted
 */

char	**addstrarr(char **arr, char *str)
{
	char	**new_arr;
	int		size;

	size = sizearr(arr);
	new_arr = (char **) malloc(sizeof(char **) * ((size + 1) + 1));
	if (new_arr != NULL)
	{
		cp_arr(new_arr, arr, size);
		new_arr[size] = str;
		new_arr[size + 1] = NULL;
		free(arr);
	}
	else
		error_msg_exit(ERROR_MALLOC);
	return (new_arr);
}
