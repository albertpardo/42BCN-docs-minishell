/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fd_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:57:30 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:28:50 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	test_fd_ok(int fd, char *m)
{
	if (fd == -1)
	{
		ft_putstr_fd(MINI, 2);
		return (error(m));
	}
	return (EXIT_SUCCESS);
}
