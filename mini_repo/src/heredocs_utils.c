/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:57:43 by apardo-m          #+#    #+#             */
/*   Updated: 2024/04/18 15:42:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

static int	is_tmp_file_heredoc(char *file)
{
	return (file && \
		!ft_strncmp(file, TEMP_FILE_NAME, ft_strlen(TEMP_FILE_NAME)));
}

/*
 *	If file (as file name) contains TEMP_FILE_NAME then 
 *		 delete(file)
 *	HOW TO CHECK IF file exits on system
 */

void	del_tmp_files_heredocs(char *file)
{
	if (is_tmp_file_heredoc(file))
		unlink(file);
}

/*
 * if *file is the type TEMP_FILE_NAME then free(file)
 */
void	free_heredoc_file_name(char *file)
{
	if (is_tmp_file_heredoc(file))
		free(file);
}
