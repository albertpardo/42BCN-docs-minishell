/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:23:54 by spereyra          #+#    #+#             */
/*   Updated: 2023/06/07 12:37:22 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] != '\0' && (ft_strchr(set, (int)s1[start])) != 0)
		start++;
	return (start);
}

static size_t	ft_get_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && (ft_strrchr(set, (int)s1[end])) != 0)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s2;

	if (s1 == 0 || set == 0)
		return (0);
	else if (s1[0] == 0 || set[0] == 0)
		s2 = ft_strdup(s1);
	else
	{
		start = ft_get_start(s1, set);
		if (start >= ft_strlen(s1))
			s2 = ft_strdup("");
		else
		{
			end = ft_get_end(s1, set);
			if (start > end)
				return (0);
			s2 = (char *)malloc((end - start + 2) * sizeof(char));
			if (s2 != 0)
				ft_strlcpy(s2, &s1[start], (end - start + 2));
		}
	}
	return (s2);
}
