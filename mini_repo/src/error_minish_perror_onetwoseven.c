/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minish_perror_onetwoseven.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:27:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 12:50:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "minishell.h"
#include "executor.h"

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
