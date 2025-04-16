/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:25:46 by spereyra          #+#    #+#             */
/*   Updated: 2023/11/25 11:29:12 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	s_len = ft_strlen(s);
	if (s_len == 0 || start >= s_len || len == 0)
	{
		sub = (char *)malloc(sizeof(char));
		if (sub != 0)
			sub[0] = '\0';
	}
	else
	{
		sub = (char *)malloc((ft_min(len, s_len - start) + 1) * sizeof(char));
		if (sub != 0)
			ft_strlcpy(sub, &s[start], ft_min(len, s_len - start) + 1);
	}
	return (sub);
}
