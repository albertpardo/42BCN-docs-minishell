/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_chang_val_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:16:16 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/22 11:26:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	change_value_pos(char **arr, int pos, char *str)
{
	free(arr[pos]);
	arr[pos] = str;
}
