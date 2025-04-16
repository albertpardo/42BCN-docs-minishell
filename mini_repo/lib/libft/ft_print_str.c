/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:42:58 by spereyra          #+#    #+#             */
/*   Updated: 2023/08/16 09:22:30 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	printed;
	int	count;

	printed = 0;
	if (!str)
	{
		printed += write(1, "(null)", 6);
		return (printed);
	}
	while (*str != '\0')
	{
		count = 0;
		count = ft_print_char((int)*str);
		if (count == -1)
			return (-1);
		printed += count;
		str++;
	}
	return (printed);
}
