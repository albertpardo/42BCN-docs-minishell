/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:55:08 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:22:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*next_heredoc_filename(int i)
{
	char		*fname;
	char		*strnum;

	fname = NULL;
	strnum = ft_itoa(i);
	fname = ft_strjoin(TEMP_FILE_NAME, strnum);
	if (fname == NULL)
		error_msg_exit(ERROR_MALLOC);
	free(strnum);
	return (fname);
}

/*
 * (*filetok)->word is not cheched for null value
 */
static int	execute_read_heredocs(int i, t_token **filetok, t_shell *shell)
{
	char		*tmp_file_name;
	int			err_res;

	tmp_file_name = next_heredoc_filename(i);
	*filetok = (*filetok)->next;
	err_res = emula_here_docs(tmp_file_name, (*filetok)->word, shell);
	free_heredoc_file_name(tmp_file_name);
	return (err_res);
}

int	read_heredocs(t_shell *shell)
{
	t_pipe		*pnode;
	t_token		*filetok;
	int			i;
	int			err_res;

	i = 0;
	err_res = 0;
	pnode = shell->pipe_lst;
	while (err_res == 0 && pnode != NULL)
	{
		filetok = pnode->in_lst;
		while (err_res == 0 && filetok != NULL)
		{
			if (filetok->oper == LESS_LESS)
				err_res = execute_read_heredocs(i, &filetok, shell);
			filetok = filetok->next;
		}
		i++;
		pnode = pnode->next;
	}
	return (err_res);
}
