/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_set_execvars_tonextstep.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:20:17 by apardo-m          #+#    #+#             */
/*   Updated: 2024/04/18 15:37:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	set_execvars_tonextstep(t_execut *execvars)
{
	del_tmp_files_heredocs(execvars->filein);
	free_heredoc_file_name(execvars->filein);
	init_files_execvars(execvars);
}
