/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:11:53 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/22 15:35:21 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* argv[0] is the 'pwd' comnand, argv[1] must be NULL
 * since options are not allowed
 * EXIT STATUS: 0 on success and >0 if an error occurs
 */

int	builtin_pwd(void)
{
	char	*folder;

	folder = NULL;
	folder = getcwd(folder, 1);
	if (folder == NULL)
		return (EXIT_FAILURE);
	ft_putendl_fd(folder, STDOUT_FILENO);
	free(folder);
	return (EXIT_SUCCESS);
}
