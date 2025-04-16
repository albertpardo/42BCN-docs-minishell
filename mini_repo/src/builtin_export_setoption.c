/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_setoption.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:56:05 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:11:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

#define EXPORT "export: `"

/*
 * return a new substring from start to (pos + 1) of str 
 */

static char	*get_substr(char *str, char *pos)
{
	int		i;
	char	*substr;

	i = 0;
	while (&str[i] != pos)
		i++;
	i++;
	substr = (char *) malloc(sizeof(char) * (i + 1));
	if (substr == NULL)
		error_exit(ERROR_MALLOC);
	ft_memset(substr, '\0', i + 1);
	ft_memmove(substr, str, i - 1);
	return (substr);
}

/*
 * set option 1 or 2
 */

static int	set_options(char **varname, int *option, char *arg, char *simbolpos)
{
	int		equalpos;

	*varname = get_substr(arg, simbolpos);
	*option = 1;
	simbolpos--;
	equalpos = ft_strlen(*varname);
	if (*simbolpos == '+')
	{
		equalpos--;
		(*varname)[equalpos] = '\0';
		*option = 2;
	}
	return (equalpos);
}

/*
 *	Set an option:
 *
 *	-1 : No valid Var Name
 *	0  : Only var name without '='. Similar to 'VAR'
 *	1  : Assignament similar to 'VAR=Some'
 *	2  : Join/concant to actual existing var 'VAR+=NewSome'
 *
 * Returns a VARNAME finished with '='
 */

int	setoption(char **varname, int *option, char *arg)
{
	char	*simbolpos;
	int		equalpos;

	*option = -1;
	*varname = NULL;
	simbolpos = ft_strchr(arg, '=');
	if (simbolpos != NULL)
		equalpos = set_options(varname, option, arg, simbolpos);
	else
	{
		*option = 0;
		*varname = ft_strdup(arg);
		if (*varname == NULL)
			error_msg_exit(ERROR_MALLOC);
	}
	if (!isvalidvarname(*varname))
		return (error_four_str(MINI, EXPORT, arg, NO_IDENTIFIER));
	return (EXIT_SUCCESS);
}
