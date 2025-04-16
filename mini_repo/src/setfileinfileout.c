/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfileinfileout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:52:40 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 12:36:30 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Tratar redirecciones entrada
 *
 *
 *  - variable FILEIN que se assignara a la STDIN
 *	- mientras (t_pipe.in_lst != NULL)
 *  - 	si (t_pipe.in_lst.oper == LESS_LESS)
 *			FILEIN = getionarHEREDOC(t_pipe.in_lst.word);
 *		else
 *  		FILEIN = t_pipe.in_lst.word
 *	- 	t_pipe.in_lst = t_pipe.in_lst.next;
 *
 */

#include "executor.h"
#define FILE_NULL "filename is NULL or \"\""
#define AMBIGUOUS ": ambiguous redirect"

static int	existfile(char *filename)
{
	int	fd;
	int	err;

	fd = open(filename, O_RDONLY);
	err = test_fd_ok(fd, filename);
	if (err == 0)
		err = test_fd_ok(close(fd), filename);
	return (err);
}

static int	setfilein(t_pipe *pnode, t_execut *execvars, int i)
{
	t_token	*filetok;
	int		err;

	err = 0;
	filetok = pnode->in_lst;
	while (err == 0 && filetok != NULL)
	{
		if (filetok->oper == LESS_LESS)
		{
			filetok = filetok->next;
			free_heredoc_file_name(execvars->filein);
			execvars->filein = next_heredoc_filename(i);
		}
		else if (filetok->oper == LESS)
		{
			filetok = filetok->next;
			execvars->filein = filetok->word;
			if (execvars->filein == NULL || *execvars->filein == '\0')
				err = error_three_str(MINI, FILE_NULL, AMBIGUOUS);
			else
				err = existfile(filetok->word);
		}
		filetok = filetok->next;
	}
	return (err);
}

/*
static int	setfileout(t_pipe *pnode, t_execut *execvars)
{
	t_token		*filetok;
	int			fd;
	int			err;

	err = EXIT_SUCCESS;
	filetok = pnode->out_lst;
	while (filetok != NULL)
	{
		if (filetok->oper == GREAT || filetok->oper == GREAT_GREAT)
		{
			if (filetok->oper == GREAT_GREAT)
				execvars->isfileoutappend = 1;
			filetok = filetok->next;
			if (filetok->word == NULL || *filetok->word == '\0')
				return (error_three_str(MINI, FILE_NULL, AMBIGUOUS));
			else
			{
				fd = open(filetok->word, O_CREAT, 0644);
				err = test_fd_ok(fd, ERROR_FILEOUT_OPEN);
				if (err == EXIT_SUCCESS)
					err = test_fd_ok(close(fd), ERROR_FILEOUT_CLOSE) != 0;
			}
			execvars->fileout = filetok->word;
		}
		filetok = filetok->next;
	}
	return (err);
}
*/

static int	exec_setfileout(char *word)
{
	int	err;
	int	fd;

	if (word == NULL || *word == '\0')
		err = error_three_str(MINI, FILE_NULL, AMBIGUOUS);
	else
	{
		fd = open(word, O_CREAT, 0644);
		err = test_fd_ok(fd, ERROR_FILEOUT_OPEN);
		if (err == EXIT_SUCCESS)
			err = test_fd_ok(close(fd), ERROR_FILEOUT_CLOSE) != 0;
	}
	return (err);
}

static int	setfileout(t_pipe *pnode, t_execut *execvars)
{
	t_token		*filetok;
	int			err;

	err = EXIT_SUCCESS;
	filetok = pnode->out_lst;
	while (filetok != NULL)
	{
		if (filetok->oper == GREAT || filetok->oper == GREAT_GREAT)
		{
			if (filetok->oper == GREAT_GREAT)
				execvars->isfileoutappend = 1;
			filetok = filetok->next;
			err = exec_setfileout(filetok->word);
			execvars->fileout = filetok->word;
		}
		filetok = filetok->next;
	}
	return (err);
}

/*
 * set filenames from
 *  all redirections in to execvars->filein
 *  all redirections out to execvars->fileout
 */

int	setfileinfileout(t_pipe *pnode, t_execut *execvars, int i)
{
	int	err;

	err = setfilein(pnode, execvars, i);
	if (err == 0)
		err = setfileout(pnode, execvars);
	return (err);
}
