/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:59:45 by spereyra          #+#    #+#             */
/*   Updated: 2023/06/06 17:07:31 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&(str[i]));
		else
			i++;
	}
	if ((char)c == '\0')
		return (&(str[i]));
	else
		return (0);
}
/*
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (str[i] != (char) c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&(str[i]));
}
*/
