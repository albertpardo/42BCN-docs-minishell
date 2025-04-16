/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:41 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/22 11:52:07 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "shlvl.h"

/*
 * for shlvl=x, 
 * where x is number, makes n = atoi(x) + 1 :
 *  - n < 0 , shlvl=0
 * 	- -1 < n < 1000, shlvl = n
 * 	- n = 1000, shlvl= '\0';
 *  - rest of cases ( 1000 < n =< 2147483647), shlvl=1 and
 *		message on screen (example n = 1002):
 *		   	bash: warning: shell level (1002) too high, resetting to 1
 * other cases for x or shlvl doesnot exist
 * 	shlvl=1
 */

void	inc_shlvl(char ***env)
{
	int		i;
	int		pos_shlvl;
	char	*shlvl;

	pos_shlvl = getposstr(*env, SHLVL);
	if (pos_shlvl != -1)
	{
		shlvl = (*env)[pos_shlvl];
		i = 6;
		if (isstrnum(&shlvl[i]) || \
			((shlvl[i] == '-' || shlvl[i] == '+') && isstrnum(&shlvl[i + 1])))
			manager_shlvl_number(&shlvl[i], pos_shlvl, *env);
		else
			change_set_shlvl_dup(SHLVL_ONE, pos_shlvl, *env);
	}
	else
		add_set_shlvl_dup(SHLVL_ONE, env);
}
