/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_avoid_simplequotes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:56:32 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 14:59:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/* 
 * Checks if all double quotes before "i" are closed,
 *  then avoids part of 'str' surrounded by simple quotes(quotes included)
 */

int	avoid_simplequotes(int i, char *str)
{
	int	j;
	int	dq_cnt;

	j = 0;
	dq_cnt = 0;
	while (str[j] && j < i)
	{
		if (str[j] == '\"')
			dq_cnt++;
		j++;
	}
	if ((dq_cnt % 2) == 0)
	{
		i++;
		while (str[i] != '\'' && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			i++;
	}
	return (i);
}
