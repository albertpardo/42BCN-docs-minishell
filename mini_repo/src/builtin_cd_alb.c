/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_alb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:11:14 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/21 10:35:21 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

static void	free_pwd_path(char *old_pwd, char *cur_pwd, char *path)
{
	if (old_pwd != 0)
		free(old_pwd);
	if (cur_pwd != 0)
		free(cur_pwd);
	if (path != 0)
		free(path);
}

static char	*get_value(char **matrix, char *key)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	len = ft_strlen(key);
	value = 0;
	while (matrix[i] != 0)
	{
		if (ft_strncmp(matrix[i], key, len) == 0 && matrix[i][len] == '=')
		{
			value = ft_strdup(&matrix[i][len + 1]);
			if (*value != '\0')
				return (value);
			else
				break ;
		}
		i++;
	}
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(key, 2);
	ft_putstr_fd(" not set\n", 2);
	return (value);
}

static void	error_chdir(char *path)
{
	int	error_save;

	error_save = errno;
	ft_putstr_fd("minishell: cd: ", 2);
	if (error_save == errno)
		perror(path);
}

static char	*getpathvalue(char **argv, char **envp)
{
	char	*path;

	if (argv[1] == 0 || ft_strncmp("~", argv[1], ft_strlen(argv[1])) == 0)
		path = get_value(envp, "HOME");
	else if (ft_strncmp("-", argv[1], ft_strlen(argv[1])) == 0)
	{
		path = get_value(envp, "OLDPWD");
		if (path != NULL)
			printf("%s\n", path);
	}
	else
		path = ft_strdup(argv[1]);
	return (path);
}

/*
 *
 * TODO:
 * 	check if getcwd fails => DONE!!
 * 	check when set_pwd_oldpwd(..) has some error
 */
int	builtin_cd(char **argv, char ***envp)
{
	char	*old_pwd;
	char	*cur_pwd;
	char	*path;

	path = getpathvalue(argv, *envp);
	if (path == 0 || *path == '\0' \
			|| ft_strncmp(".", path, ft_strlen(path)) == 0)
	{
		free(path);
		return (1);
	}
	old_pwd = getcwd(0, 1);
	if (old_pwd == NULL)
		old_pwd = get_value(*envp, "PWD");
	if (chdir(path) < 0)
	{
		error_chdir(path);
		free(old_pwd);
		free(path);
		return (1);
	}
	cur_pwd = getcwd(0, 1);
	set_pwd_oldpwd(old_pwd, cur_pwd, envp);
	free_pwd_path(old_pwd, cur_pwd, path);
	return (0);
}
/* Original: falla con rm -rf ../currentDir
int	builtin_cd(char **argv, char ***envp)
{
	char	*old_pwd;
	char	*cur_pwd;
	char	*path;

	path = getpathvalue(argv, *envp);
	if (path == 0 || *path == '\0')
	{
		free(path);
		return (1);
	}
	old_pwd = getcwd(0, 1);
	if (chdir(path) < 0)
	{
		error_chdir(path);
		free(old_pwd);
		free(path);
		return (1);
	}
	cur_pwd = getcwd(0, 1);
	set_pwd_oldpwd(old_pwd, cur_pwd, envp);
	free_pwd_path(old_pwd, cur_pwd, path);
	return (0);
}*/
