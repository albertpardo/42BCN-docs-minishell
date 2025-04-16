/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:04:04 by spereyra          #+#    #+#             */
/*   Updated: 2023/05/16 10:53:30 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	i = 0;
	uc_dst = (unsigned char *) dst;
	uc_src = (unsigned char *) src;
	if (!dst && !src)
		return (0);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			uc_dst[i] = uc_src[i];
		}
	}
	return (dst);
}
/*
#include <stdio.h>

int main()
{
	char *src = "thi\xffs i\xfas \0a g\xde\xadood \0nyan\0cat\0 !\r\n";
 	int size = 33;
// 	char dst1[0xF0];
 	char dst2[33];
	printf("%s\n", ft_memmove(dst2, src, size));
}
*/
