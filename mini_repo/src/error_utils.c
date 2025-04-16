/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:55:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:53:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "minishell.h"
#include "executor.h"

void	errorwrite(char *m)
{
	ft_putstr_fd(m, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	error_exit(char *m)
{
	errorwrite(m);
	exit (EXIT_FAILURE);
}

int	error(char *m)
{
	errorwrite(m);
	return (EXIT_FAILURE);
}

int	error_three_str(char *str1, char *str2, char *str3)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);
	return (EXIT_FAILURE);
}

int	error_four_str(char *str1, char *str2, char *str3, char *str4)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	ft_putendl_fd(str4, 2);
	return (EXIT_FAILURE);
}
/*
void	minish_perror_onetwoseven(char *msg)
{
	char	*tmpstr;

	tmpstr = ft_strjoin(MINI, msg);
	if (tmpstr != NULL)
	{
		perror(tmpstr);
		free(tmpstr);
		exit (127);
	}
	exit (EXIT_FAILURE);
}
*/
