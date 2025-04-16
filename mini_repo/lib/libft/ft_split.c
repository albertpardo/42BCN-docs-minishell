/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:42:18 by spereyra          #+#    #+#             */
/*   Updated: 2024/03/26 13:58:32 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdcounter(char const *s, char sep)
{
	int	i;
	int	wds;

	i = 0;
	wds = 0;
	if (s == 0 || s[0] == '\0')
		return (0);
	else if (sep == '\0')
		return (1);
	while (s[i] != '\0')
	{
		while (s[i] == sep)
			i++;
		if (s[i] == '\0')
			return (0);
		while (s[i] != sep && s[i] != '\0')
			i++;
		wds++;
		while (s[i] == sep)
			i++;
	}
	return (wds);
}

static void	ft_free_all(char **ar, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

static char	**ft_create_split(char **ar, char const *s, char c)
{
	int		ch;
	int		first_ch;
	int		wd;
	int		wd_cnt;

	ch = 0;
	wd = 0;
	wd_cnt = ft_wdcounter(s, c);
	while (s[ch] != '\0' && wd < wd_cnt)
	{
		while (s[ch] == c)
			ch++;
		first_ch = ch;
		while (s[ch] != c && s[ch] != '\0')
			ch++;
		ar[wd] = ft_substr(s, first_ch, ch - first_ch);
		if (ar[wd] == 0)
		{
			ft_free_all(ar, wd);
			return (0);
		}
		wd++;
	}
	ar[wd] = 0;
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	char	**ar;

	if (s == 0)
		return (0);
	ar = (char **)malloc(((ft_wdcounter(s, c)) + 1) * sizeof(char *));
	if (ar != 0)
		ar = ft_create_split(ar, s, c);
	return (ar);
}
