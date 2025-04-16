/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:45:05 by spereyra          #+#    #+#             */
/*   Updated: 2023/06/10 10:55:54 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned short	ft_digits(int n)
{
	unsigned short	digits;

	digits = 1;
	if (n < 0)
		n = (-1) * n;
	while ((n / 10) > 0)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

static int	ft_power(int base, int exp)
{
	int	power;

	power = 1;
	if (!(base == 0 && exp == 0))
	{
		if (exp == 0)
			return (1);
		else if (base == 0)
			return (0);
		else
		{
			while (exp > 0)
			{
				power = power * base;
				exp--;
			}
		}
	}
	return (power);
}

static char	*ft_itoa_neg(int n)
{
	char			*args;
	int				i;
	unsigned short	digits;

	n = (-1) * n;
	i = 1;
	digits = ft_digits(n) + 1;
	args = (char *)malloc((digits + 1) * sizeof(char));
	if (args == 0)
		return (0);
	else
	{
		args[0] = '-';
		while (i < digits)
		{
			args[i] = (n / ft_power(10, digits - i - 1)) + 48;
			n = n % ft_power(10, digits - i - 1);
			i++;
		}
		args[i] = '\0';
	}
	return (args);
}

char	*ft_itoa(int n)
{
	char			*args;
	int				i;
	unsigned short	digits;

	if (n == -2147483648)
		args = ft_strdup("-2147483648");
	else if (n > -2147483648 && n < 0)
		args = ft_itoa_neg(n);
	else
	{
		i = 0;
		digits = ft_digits(n);
		args = (char *)malloc((digits + 1) * sizeof(char));
		if (args == 0)
			return (0);
		while (i < digits)
		{
			args[i] = (n / ft_power(10, digits - i - 1)) + 48;
			n = n % ft_power(10, digits - i - 1);
			i++;
		}
		args[i] = '\0';
	}
	return (args);
}
