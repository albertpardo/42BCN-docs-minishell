/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:16:39 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/22 14:41:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Write on STDOUT all arguments of echo with an ending newline
 *
 * If -n option is set (one or more times) at the begining, 'nl' is omitted
 *
 * 'char **argv' contains all arguments to print on screen
 *  argv[0] is the 'echo' command
 */

static void	ft_putendsp_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, " ", 1);
}

static void	safe_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
}

void	builtin_echo(char **argv)
{
	int	nl;
	int	i;
	int	j;

	i = 1;
	nl = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n')
	{
		j = 2;
		while (argv[i][j] == 'n')
			j++;
		if (argv[i][j] == '\0')
		{
			nl = 0;
			i++;
		}
		else
			break ;
	}
	while (argv[i] && argv[i + 1])
		ft_putendsp_fd(argv[i++], STDOUT_FILENO);
	safe_putstr_fd(argv[i], STDOUT_FILENO);
	if (nl == 1)
		ft_putchar_fd('\n', 1);
}

/* 
int	builtin_echo(char **argv)
{
	int	no_nl;
	int	i;

	i = 1;
	no_nl = 0;
	while (argv[i] && ft_strncmp("-n", argv[i], ft_strlen(argv[i])) == 0)
	{
		no_nl = 1;
		i++;
	}
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!no_nl)
		ft_putchar_fd('\n', 1);
	return (0);
}
*/
