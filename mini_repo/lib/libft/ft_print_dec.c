/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:43:30 by spereyra          #+#    #+#             */
/*   Updated: 2023/08/16 18:18:09 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_num(long d)
{
	int		printed;
	int		i;
	char	v[20];

	printed = 0;
	i = 0;
	while (d > 0)
	{
		v[i++] = (d % 10) + '0';
		d = d / 10;
	}
	while (--i >= 0)
	{
		if ((ft_print_char((int)v[i])) == -1)
			return (-1);
		printed++;
	}
	return (printed);
}

int	ft_print_dec(long d)
{
	int	printed;
	int	i;

	printed = 0;
	i = 0;
	if (d < 0)
	{
		printed = write(1, "-", 1);
		d = (-1) * d;
	}
	if (d == 0)
		printed = write(1, "0", 1);
	if (printed == -1)
		return (-1);
	else
		printed += ft_print_num(d);
	return (printed);
}
