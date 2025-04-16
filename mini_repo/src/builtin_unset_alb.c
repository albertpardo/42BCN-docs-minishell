/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset_alb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:24:28 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:12:32 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	builtin_unset(char **argv, char ***env)
{
	int	err;
	int	cmdpos;
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (isvalidvarname(argv[i]))
		{
			if (i == 0)
				err = EXIT_SUCCESS;
			cmdpos = getposstr(*env, argv[i]);
			if (cmdpos != -1)
			{
				*env = rmposarr(*env, cmdpos);
				if (*env == NULL)
					error_msg_exit(ERROR_MALLOC);
			}
		}
		else
			err = error_four_str(MINI, "unset: '", argv[i], NO_IDENTIFIER);
		i++;
	}
	return (err);
}
