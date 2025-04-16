/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xlo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:44:06 by spereyra          #+#    #+#             */
/*   Updated: 2023/08/16 10:25:37 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xlo(long x)
{
	int		i;
	int		printed;
	int		count;
	char	*symbols;
	char	v[20];

	printed = 0;
	symbols = "0123456789abcdef";
	i = 0;
	if (x == 0)
		printed = ft_print_char((int)symbols[0]);
	while (x > 0)
	{
		v[i++] = symbols[x % 16];
		x = x / 16;
	}
	while (--i >= 0)
	{
		count = 0;
		count += ft_print_char((int)v[i]);
		if (count == -1)
			return (-1);
		printed += count;
	}
	return (printed);
}
