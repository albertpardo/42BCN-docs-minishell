/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:41:24 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/22 11:04:43 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * bltin_env(char **env)
 *
 * 'env' : Is an array of char pointers
 *
 * Write on stdout the 'env' array of strings
 */

void	bltin_env(char **env)
{
	while (*env != NULL)
	{
		if (ft_strchr(*env, '=') != NULL)
			ft_putendl_fd(*env, STDOUT_FILENO);
		env++;
	}
}
