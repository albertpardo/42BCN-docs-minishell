/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del_oldpwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:48:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:12:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

#define OLDPWD "OLDPWD"

char	**env_del_oldpwd(char **env)
{
	int		pos;

	pos = getposstr(env, OLDPWD);
	if (pos != -1)
		return (rmposarr(env, pos));
	return (env);
}

void	reset_oldpwd(char ***env)
{
	int		pos;
	char	*str;

	pos = getposstr(*env, OLDPWD);
	if (pos != -1)
	{
		str = ft_strdup(OLDPWD);
		if (str != NULL)
			change_value_pos(*env, pos, str);
		else
			error_msg_exit(ERROR_MALLOC);
	}
}
