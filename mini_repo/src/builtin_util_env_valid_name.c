/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util_env_valid_name.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:19:08 by apardo-m          #+#    #+#             */
/*   Updated: 2024/04/28 10:20:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/*
 *	check if stars with '_' or alphabetic char  and the rest of chars are 
 *	alphanumeric
 *
 */

int	isvalidvarname(const char *str)
{
	if (str != NULL && (*str == '_' || ft_isalpha(*str)))
	{
		while (*str != '\0' && (*str == '_' || ft_isalnum(*str)))
			str++;
		if (*str == '\0')
			return (TRUE);
	}
	return (FALSE);
}
