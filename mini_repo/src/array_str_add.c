/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_str_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:07:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:08:25 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
 * Manage error when add a str to env
 */

void	add_new_var(char ***env, char *str)
{
	*env = addstrarr(*env, str);
	if (*env == NULL)
		error_msg_exit(ERROR_MALLOC);
}
