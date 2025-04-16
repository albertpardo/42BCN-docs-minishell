/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:38:01 by spereyra          #+#    #+#             */
/*   Updated: 2023/05/23 12:42:56 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_of_needle;

	i = 0;
	len_of_needle = ft_strlen(needle);
	if (len_of_needle == 0)
		return ((char *) haystack);
	if (len == 0 || haystack[0] == '\0')
		return (0);
	else
	{
		while (i < len && (len - i) >= len_of_needle && haystack[i] != '\0')
		{
			if (ft_strncmp(&(haystack[i]), needle, len_of_needle) == 0)
				return ((char *)(&(haystack[i])));
			else
				i++;
		}
	}
	return (0);
}
