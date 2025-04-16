/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:22:56 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 15:06:41 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_token(char *wd, t_operator op, t_token **token_lst)
{
	t_token	*node;

	node = newtoken(wd, op);
	if (!node)
		return (0);
	tokenlst_addback_2(token_lst, node);
	return (1);
}

t_token	*newtoken(char *wd, t_operator op)
{
	t_token		*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (0);
	new_token->word = wd;
	new_token->oper = op;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

int	tokenlst_size(t_token *token_lst)
{
	int	size;

	size = 0;
	while (token_lst)
	{
		size++;
		token_lst = token_lst->next;
	}
	return (size);
}

void	tokenlst_addback_2(t_token **token_lst, t_token *new_token)
{
	t_token	*head;

	head = *token_lst;
	if (*token_lst == NULL)
	{
		*token_lst = new_token;
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = new_token;
	new_token->prev = head;
}
