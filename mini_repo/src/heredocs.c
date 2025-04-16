/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:26:43 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 12:53:56 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> /* definicions O_RDONLY, O_WRONLY, ... */
#include <unistd.h>
#include <sys/wait.h>

#include "minishell.h"
#include "executor.h"

//
//	START  heredoc in fork
//

static void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		exit(EXIT_FAILURE);
	}
}

/*
 *  CRTL + D  similar to EOF or NULL
 *	"readline" returns NULL when CTRL + D is pressed
 *  In this case "ANSI Escape Sequences" is used to put the line similar to BASH
 *  See : https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 *  Where :
 *  \033 is the octal value var ESC
 * 	[1K  Delete chars from start current line to actual cursor position
 * 	\r   Put the cursor to start current line 
 */

static void	emulation_heredoc(char *strlimit, int fd, t_shell *shell)
{
	char	*line;
	char	*line_expanded;

	line = readline("> ");
	while (line != NULL && ft_strncmp(line, strlimit, ft_strlen(strlimit) + 1))
	{
		line_expanded = dollar_expand(line, shell);
		ft_putendl_fd(line_expanded, fd);
		free(line_expanded);
		free(line);
		line = readline("> ");
	}
	if (line == NULL)
		ft_putstr_fd("\033[1K\r> ", STDOUT_FILENO);
	free(line);
}

/* 
 * executes hererdoc in a fork. Each fork manage SIGINT
 */

static int	exec_heredoc(char *str_limit, int fd, t_shell *shell)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error(ERROR_HERE_FORK);
	if (pid == 0)
	{
		signal(SIGINT, &heredoc_handler);
		signal(SIGQUIT, SIG_IGN);
		emulation_heredoc(str_limit, fd, shell);
		exit (EXIT_SUCCESS);
	}
	wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT))
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

//
//	END  heredoc in fork
//

//
//	START  heredoc in Main (father)
//

/*
static void	heredoc_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
	{
//		printf("\n");
//		rl_replace_line("\n\033[1E", 1);
//		rl_replace_line("\0330x0D", 1);
//		rl_on_new_line();
//		rl_redisplay();
	}
}
*/

/*
 *  CRTL + D  similar to EOF or NULL
 *	"readline" returns NULL when CTRL + D is pressed
 *  In this case "ANSI Escape Sequences" is used to put the line similar to BASH
 *  See : https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 *  Where :
 *  \033 is the octal value var ESC
 * 	[1K  Delete chars from start current line to actual cursor position
 * 	\r   Put the cursor to start current line 
 */

/*
static int	emulation_heredoc(char *strlimit, int fd, t_shell *shell)
{
	char	*line;
	char	*line_expanded;

	line = readline("> ");
	while (line != NULL && ft_strncmp(line, strlimit, ft_strlen(strlimit) + 1))
	{
		line_expanded = dollar_expand(line, shell);
		ft_putendl_fd(line_expanded, fd);
		free(line_expanded);
		free(line);
		line = readline("> ");
// intento interpretacion señal
		if (g_signal == SIGINT)
		{
			g_signal = 0;
			return (EXIT_FAILURE);
		}
// fin intento
	}
	if (line == NULL)
		ft_putstr_fd("\033[1K\r> ", STDOUT_FILENO);
	free(line);
	return (EXIT_SUCCESS);
}

static int	exec_heredoc(char *str_limit, int fd, t_shell *shell)
{
	signal(SIGINT, &heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
	return (emulation_heredoc(str_limit, fd, shell));
}
*/

//
//	END  heredoc in Main (father)
//

int	emula_here_docs(char *filename, char *str_limit, t_shell *shell)
{
	int	err_res;
	int	fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	err_res = test_fd_ok(fd, ERROR_HERE_OPEN);
	if (err_res == EXIT_SUCCESS)
		err_res = exec_heredoc(str_limit, fd, shell);
	if (close(fd) == -1)
		err_res = error(ERROR_HERE_CLOSE);
	return (err_res);
}
