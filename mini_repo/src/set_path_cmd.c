/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:12:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:22:49 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

#include "minishell.h"
#include "executor.h"

#define PATH_NAME "PATH"
#define COMMAND_NOT_FOUND ": command not found"
#define CODE_COMMAND_NOT_FOUND 127
#define MSG_IS_DIR ": is a directory"
#define CODE_IS_DIR	126
#define TRUE 1
#define FALSE 0

/*
 * Returns TRUE if 'path' is an executable file. Otherwise, returns FALSE.
 */

/*
 * Significado de : F_OK  test if file exist
 *
 * Hay esta otra alternativa 
 *
 * if (access(path, X_OK) == -1)   
 *  X_OK  test if file can be acces for execute/search
 *
 */

static int	can_execute(const char *path)
{
	if (access(path, F_OK) == -1)
		return (FALSE);
	return (TRUE);
}

static char	*get_path_cmd(char *cmd, char **arrpath)
{
	char	*tmp;
	char	*path_cmd;
	int		i;

	i = 0;
	while (arrpath[i] != NULL)
	{
		tmp = ft_strjoin(arrpath[i], "/");
		path_cmd = ft_strjoin(tmp, cmd);
		if (path_cmd == NULL)
			error_msg_exit(ERROR_MALLOC);
		free(tmp);
		if (can_execute(path_cmd))
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	return (NULL);
}

/*
 *
 * Options for 'cmd' :
 * 
 * exec by PATH
 * is DIR
 * can be exec with absolute or relative path
 */

static int	real_set_path_cmd(char **path_and_cmd, char **arpath, char *cmd)
{
	struct stat	stats;

	stat(cmd, &stats);
	if (arpath != NULL && get_builtin(cmd) == -1 && ft_strchr(cmd, '/') == NULL)
		*path_and_cmd = get_path_cmd(cmd, arpath);
	else if (S_ISDIR(stats.st_mode))
	{
		error_three_str(MINI, cmd, MSG_IS_DIR);
		return (CODE_IS_DIR);
	}
	else
		*path_and_cmd = ft_strdup(cmd);
	if (*path_and_cmd == NULL)
	{
		error_three_str(MINI, cmd, COMMAND_NOT_FOUND);
		return (CODE_COMMAND_NOT_FOUND);
	}
	return (EXIT_SUCCESS);
}

// START Looks for path for each command in PIPES 

/*
 * Looks for each command in th folders in PATH environment and
 * test if the command can be executable
 */

/*
int	set_path_cmd(t_pipe *pnode, char **env)
{
	char	*pathptr;
	char	**arpath;
	char	*cmd;
	int		err;

	err = EXIT_SUCCESS;
	pathptr = ft_getenv(env, PATH_NAME);
	arpath = ft_split(pathptr, ':');
	while (pnode != NULL && err == EXIT_SUCCESS)
	{
		cmd = pnode->argv_exec[0];
		if (cmd != NULL)
			err = real_set_path_cmd(&(pnode->path_and_cmd), arpath, cmd);
		pnode = pnode->next;
	}
	free_matrix(arpath);
	free(pathptr);
	return (err);
}
*/

// END  Looks for path for each command in PIPES 

// START Looks for one command' path

int	set_path_cmd(t_pipe *pnode, char **env)
{
	char	*pathptr;
	char	**arpath;
	char	*cmd;
	int		err;

	err = EXIT_SUCCESS;
	pathptr = ft_getenv(env, PATH_NAME);
	arpath = ft_split(pathptr, ':');
	cmd = pnode->argv_exec[0];
	if (cmd != NULL && *cmd != '\0')
		err = real_set_path_cmd(&(pnode->path_and_cmd), arpath, cmd);
	free_matrix(arpath);
	free(pathptr);
	return (err);
}

// END Looks for one command' path
