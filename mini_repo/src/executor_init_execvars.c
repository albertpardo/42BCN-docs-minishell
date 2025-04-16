/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_init_execvars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:15:22 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/27 15:33:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	init_execvars(t_execut *vars)
{
	vars->fdin = -1;
	vars->tmp_in = vars->fdin;
	vars->tmp_out = vars->fdin;
	vars->fdout = vars->fdin;
	vars->next_fdin = vars->fdin;
	vars->next_pipe[PIPE0_STDIN] = vars->fdin;
	vars->next_pipe[PIPE1_STDOUT] = vars->fdin;
	init_files_execvars(vars);
}
