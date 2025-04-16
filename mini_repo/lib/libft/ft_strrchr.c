/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:09:53 by spereyra          #+#    #+#             */
/*   Updated: 2023/05/17 11:10:20 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *) s;
	while ((str[i] != (char) c) && (i >= 0))
	{
		if (i == 0)
			return (0);
		i--;
	}
	return (&(str[i]));
}
/*
#include <string.h>
#include <stdio.h>

int main() {

  char str[] = "Dabale arroz a la zorra el abad";

  printf("Returned address from strrchr is:\t%p\n", strrchr(str, '\0'));
  printf("Returned address from ft_strrchr is:\t%p\n", ft_strrchr(str, '\0'));
  
  printf("Returned address from strrchr is:\t%p\n", strrchr(str, 'd'));
  printf("Returned address from ft_strrchr is:\t%p\n", ft_strrchr(str, 'd'));
  
  printf("Returned address from strrchr is:\t%p\n", strrchr(str, 'a'));
  printf("Returned address from ft_strrchr is:\t%p\n", ft_strrchr(str, 'a'));
  
  printf("Returned address from strrchr is:\t%p\n", strrchr(str, 'b'));
  printf("Returned address from ft_strrchr is:\t%p\n", ft_strrchr(str, 'b'));
  
  printf("Returned address from strrchr is:\t%p\n", strrchr(str, ' '));
  printf("Returned address from ft_strrchr is:\t%p\n", ft_strrchr(str, ' '));

  return 0;
}
*/
