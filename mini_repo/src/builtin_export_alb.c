/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_alb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:37:09 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:10:18 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/*
 * Export without arguments.
 * Prints enviroment var except the var than stars with "_="
 */

static void	putexportenv(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		if (ft_strncmp(env[i], "_=", 2) != 0)
		{
			ft_putstr_fd("declare -x ", 1);
			while (env[i][j] != '\0' && env[i][j] != '=')
				ft_putchar_fd(env[i][j++], 1);
			if (env[i][j] == '=')
			{
				ft_putchar_fd(env[i][j++], 1);
				ft_putchar_fd('\"', 1);
				ft_putstr_fd(&env[i][j], 1);
				ft_putchar_fd('\"', 1);
			}
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
}

/*
static int	option_zero(char *varname, char ***env)
{
	int		err;
	int		vararrpos;
	char	*newstr;

	err = EXIT_SUCCESS;
	vararrpos = getposstr(*env, varname);
	newstr = ft_strdup(varname);
	if (vararrpos == -1 && newstr != NULL)
		err = add_new_var(env, newstr);
	return (err);
}
*/

/*
 * if 'varname' is not in 'env' 
 * 	then 'varname' is added to 'env'
 * 		
 */

static void	option_zero(char *varname, char ***env)
{
	int		vararrpos;
	char	*newstr;

	if (!(ft_strlen(varname) == 1 && *varname == '_'))
	{
		vararrpos = getposstr(*env, varname);
		newstr = ft_strdup(varname);
		if (vararrpos == -1 && newstr != NULL)
			add_new_var(env, newstr);
		else if (newstr == NULL)
			error_msg_exit(ERROR_MALLOC);
	}
}

/*
static int	export_with_arg(char **argv, char ***env)
{
	int		err;
	int		err_aux;
	int		i;
	int		option;
	char	*varname;

	err = EXIT_SUCCESS;
	i = 1;
	while (argv[i] != NULL)
	{
		err_aux = setoption(&varname, &option, argv[i]);
		if (err_aux == EXIT_SUCCESS)
		{
			if (option == 0 || ft_strncmp(varname, "_=", 2) == 0)
				err_aux = EXIT_SUCCESS;
			else if (option == 1 || option == 2)
				err_aux = manage_onetwo(option, varname, argv[i], env);
		}
		if (err_aux == EXIT_FAILURE)
			err = err_aux;
		free(varname);
		i++;
	}
	return (err);
}
*/

/*
static int	export_with_arg(char **argv, char ***env)
{
	int		err;
	int		err_aux;
	int		i;
	int		option;
	char	*varname;

	err = EXIT_SUCCESS;
	i = 1;
	while (argv[i] != NULL)
	{
		err_aux = setoption(&varname, &option, argv[i]);
		if (err_aux == EXIT_SUCCESS)
		{
			if ((ft_strlen(varname) == 1 && *varname == '_') || \
					ft_strncmp(varname, "_=", 2) == 0)
				err_aux = EXIT_SUCCESS;
			else if (option == 0)
				option_zero(varname, env);
			else if (option == 1 || option == 2)
				err_aux = manage_onetwo(option, varname, argv[i], env);
		}
		if (err_aux == EXIT_FAILURE)
			err = err_aux;
		free(varname);
		i++;
	}
	return (err);
}
*/

static int	export_with_arg(char **argv, char ***env)
{
	int		err;
	int		err_aux;
	int		i;
	int		option;
	char	*varname;

	err = EXIT_SUCCESS;
	i = 1;
	while (argv[i] != NULL)
	{
		err_aux = setoption(&varname, &option, argv[i]);
		if (err_aux == EXIT_SUCCESS && option == 0)
			option_zero(varname, env);
		else if (err_aux == EXIT_SUCCESS && (option == 1 || option == 2))
			manage_onetwo(option, varname, argv[i], env);
		if (err_aux == EXIT_FAILURE)
			err = EXIT_FAILURE;
		free(varname);
		i++;
	}
	return (err);
}

/*
 * if argument of export is "_" or starts with "_=" 
 *   nothing done and EXIT_SUCCESS
 */

int	builtin_export(char **argv, char ***env)
{
	int		err;

	err = EXIT_SUCCESS;
	if (argv[1] == NULL)
		putexportenv(*env);
	else
		err = export_with_arg(argv, env);
	return (err);
}
