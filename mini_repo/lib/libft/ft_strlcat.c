/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:57:22 by spereyra          #+#    #+#             */
/*   Updated: 2023/05/16 13:21:07 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	char		*d;
	int			d_len;
	size_t		n_chars;

	s = src;
	d = dst;
	n_chars = dstsize;
	while (n_chars-- != 0 && *d != '\0')
		d++;
	d_len = d - dst;
	n_chars = dstsize - d_len;
	if (n_chars == 0)
		return (d_len + ft_strlen(src));
	while (*s != '\0')
	{
		if (n_chars != 1)
		{
			*d++ = *s;
			n_chars--;
		}
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}
