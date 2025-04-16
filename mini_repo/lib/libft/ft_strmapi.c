/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:59:02 by spereyra          #+#    #+#             */
/*   Updated: 2023/06/10 11:51:16 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*sf;

	sf = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (sf == 0)
		return (0);
	else
	{
		i = 0;
		while (i < ft_strlen(s))
		{
			sf[i] = f(i, s[i]);
			i++;
		}
		sf[i] = '\0';
		return (sf);
	}
}
