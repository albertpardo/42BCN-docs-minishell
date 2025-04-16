/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:33:26 by spereyra          #+#    #+#             */
/*   Updated: 2023/05/24 09:59:08 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	i = 0;
	ucs1 = (unsigned char *) s1;
	ucs2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ucs1[i] == ucs2[i])
			i++;
		else
			return (ucs1[i] - ucs2[i]);
	}
	return (0);
}
