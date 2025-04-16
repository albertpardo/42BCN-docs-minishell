/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_manage_onetwo.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:40:38 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:10:42 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/* 
 * Join new content at the end of an exist environment variable.
 * If Not exist the variable and content is added.
 */

static void	env_var_join(char *equalpos, int vararrpos, char ***env)
{
	char	*newstring;

	newstring = ft_strjoin((*env)[vararrpos], equalpos);
	if (newstring != NULL)
	{
		free((*env)[vararrpos]);
		(*env)[vararrpos] = newstring;
	}
	else
		error_exit(ERROR_MALLOC);
}

/*
 * Example cases export
 * - option 1 -> export VAR=.....
 * - option 2 -> export VAR+=....
 */
/*
int	manage_onetwo(int option, char *varname, char *arg, char ***env)
{
	char	*newstring;
	char	*equalpos;
	int		vararrpos;
	int		err;

	vararrpos = getposstr(*env, varname);
	equalpos = ft_strchr(arg, '=');
	if (vararrpos == -1 || option == 1)
		newstring = ft_strjoin(varname, equalpos);
	else
		newstring = ft_strjoin(varname, ++equalpos);
	if (newstring != NULL)
	{
		if (vararrpos != -1 && option == 2)
			err = env_var_join(equalpos, vararrpos, env);
		else if (vararrpos != -1 && option == 1)
			err = change_value_pos(*env, vararrpos, newstring);
		else
			err = add_new_var(env, newstring);
	}
	else
		err = error(ERROR_MALLOC);
	return (err);
}
*/

void	manage_onetwo(int option, char *varname, char *arg, char ***env)
{
	char	*newstring;
	char	*equalpos;
	int		vararrpos;

	if (!(ft_strlen(varname) == 1 && *varname == '_'))
	{
		vararrpos = getposstr(*env, varname);
		equalpos = ft_strchr(arg, '=');
		if (vararrpos == -1 || option == 1)
			newstring = ft_strjoin(varname, equalpos);
		else
			newstring = ft_strjoin(varname, ++equalpos);
		if (newstring != NULL)
		{
			if (vararrpos != -1 && option == 2)
				env_var_join(equalpos, vararrpos, env);
			else if (vararrpos != -1 && option == 1)
				change_value_pos(*env, vararrpos, newstring);
			else
				add_new_var(env, newstring);
		}
		else
			error_msg_exit(ERROR_MALLOC);
	}
}
