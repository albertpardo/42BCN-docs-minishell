/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:24:21 by spereyra          #+#    #+#             */
/*   Updated: 2023/08/16 11:47:05 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				printed;
	int				i;
	char			*symbols;
	char			v[20];

	printed = 0;
	i = 0;
	symbols = "0123456789abcdef";
	if ((write(1, "0x", 2)) == -1)
		return (-1);
	printed = 2;
	if (ptr == 0)
		printed += write(1, "0", 1);
	while (ptr > 0)
	{
		v[i++] = symbols[(unsigned long)ptr % 16];
		ptr = (void *)((unsigned long)ptr / 16);
	}
	while (--i >= 0)
	{
		if ((ft_print_char((int)v[i])) == -1)
			return (-1);
		printed++;
	}
	return (printed);
}
