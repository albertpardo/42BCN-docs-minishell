/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:43:44 by spereyra          #+#    #+#             */
/*   Updated: 2023/08/16 09:15:08 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	printed;

	printed = 0;
	if (specifier == '%')
		printed += write(1, "%", 1);
	else if (specifier == 'c')
		printed += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		printed += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		printed += ft_print_ptr(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		printed += ft_print_dec((long)va_arg(ap, int));
	else if (specifier == 'u')
		printed += ft_print_dec((long)va_arg(ap, unsigned int));
	else if (specifier == 'x')
		printed += ft_print_xlo((long)va_arg(ap, unsigned int));
	else if (specifier == 'X')
		printed += ft_print_xup((long)va_arg(ap, unsigned int));
	else
		printed += write(1, &specifier, 1);
	return (printed);
}
