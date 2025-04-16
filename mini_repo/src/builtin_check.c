/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:50:46 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/22 14:09:46 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	get_builtin(char *comm)
{
	char	*builtins[7];
	int		i;
	int		bltlen;
	int		commlen;

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	if (comm)
		commlen = (int) ft_strlen(comm);
	i = 0;
	while (comm && i < 7)
	{
		bltlen = ft_strlen(builtins[i]);
		if (bltlen == commlen && ft_strncmp(builtins[i], comm, bltlen) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	exec_builtin(int bltnum, char **argv_exec, t_shell *shell)
{
	int		err;

	err = EXIT_SUCCESS;
	if (bltnum == 0)
		builtin_echo(argv_exec);
	else if (bltnum == 1)
		err = builtin_cd(argv_exec, &(shell->envp_exec));
	else if (bltnum == 2)
		err = builtin_pwd();
	else if (bltnum == 3)
		err = builtin_export(argv_exec, &(shell->envp_exec));
	else if (bltnum == 4)
		err = builtin_unset(argv_exec, &(shell->envp_exec));
	else if (bltnum == 5)
		bltin_env(shell->envp_exec);
	else if (bltnum == 6)
		builtin_exit(argv_exec, shell);
	return (err);
}
