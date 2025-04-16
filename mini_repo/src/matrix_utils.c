/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:00:05 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/07 12:29:19 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**dup_matrix(char **matrix)
{
	char	**new_matrix;
	int		matrix_len;
	int		i;

	i = 0;
	matrix_len = 0;
	new_matrix = 0;
	while (matrix && matrix[i++])
		matrix_len++;
	new_matrix = malloc((matrix_len + 1) * sizeof(char *));
	if (!new_matrix)
		return (0);
	i = 0;
	while (i < matrix_len)
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		if (new_matrix[i] == 0)
		{
			free_matrix(new_matrix);
			return (0);
		}
		i++;
	}
	new_matrix[i] = 0;
	return (new_matrix);
}

char	**tokenlst_to_matrix(t_token *token_lst)
{
	char	**matrix;
	int		tokenlst_len;
	int		i;

	i = 0;
	tokenlst_len = tokenlst_size(token_lst);
	matrix = 0;
	matrix = malloc((tokenlst_len + 1) * sizeof(char *));
	if (!matrix)
		return (0);
	while (token_lst)
	{
		if (token_lst->word)
			matrix[i++] = ft_strdup(token_lst->word);
		token_lst = token_lst->next;
	}
	matrix[i] = 0;
	return (matrix);
}
