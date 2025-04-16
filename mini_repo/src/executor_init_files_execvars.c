/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_init_files_execvars.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:07:11 by apardo-m          #+#    #+#             */
/*   Updated: 2024/04/18 15:14:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	init_files_execvars(t_execut *vars)
{
	vars->filein = NULL;
	vars->fileout = NULL;
	vars->isfileoutappend = 0;
}
