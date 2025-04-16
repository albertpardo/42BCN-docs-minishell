/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:42:26 by spereyra          #+#    #+#             */
/*   Updated: 2023/08/16 09:12:14 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	argsptr;
	int		count;
	int		printed;

	printed = 0;
	va_start(argsptr, format);
	while (*format != '\0')
	{
		count = 0;
		if (*format == '%')
			count = ft_print_format(*(++format), argsptr);
		else
			count = write(1, format, 1);
		if (count == -1)
			return (-1);
		printed += count;
		++format;
	}
	va_end(argsptr);
	return (printed);
}
