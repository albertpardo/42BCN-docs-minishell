/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_sets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:36:31 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:09:38 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/*
 *	Set 'varname' with its 'value' in 'env'
 */

void	set_varname(char *varname, char *value, char ***env)
{
	int		posenv;
	char	*withequal;
	char	*str;

	withequal = ft_strjoin(varname, "=");
	if (withequal == NULL)
		error_msg_exit(ERROR_MALLOC);
	str = ft_strjoin(withequal, value);
	if (str == NULL)
		error_msg_exit(ERROR_MALLOC);
	free(withequal);
	posenv = getposstr(*env, varname);
	if (posenv != -1)
		change_value_pos(*env, posenv, str);
	else
		add_new_var(env, str);
}

/*
 *	Set OLDPWD and PWD values on the environtment copy 'env'
 */

void	set_pwd_oldpwd(char *old_pwd, char *pwd, char ***env)
{
	set_varname("OLDPWD", old_pwd, env);
	set_varname("PWD", pwd, env);
}
