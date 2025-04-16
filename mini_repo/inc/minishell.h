/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:03:42 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY
# endif

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <readline.h>
# include <history.h>

/* ONLY for the number of the received signal */
/* This number IS NOT the exit status! */
int	g_signal;

typedef enum s_operator
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}			t_operator;

typedef struct s_token
{
	struct s_token	*next;
	struct s_token	*prev;
	char			*word;
	t_operator		oper;
}				t_token;

typedef struct s_pipe
{
	char			**argv_exec;
	char			*path_and_cmd;
	t_token			*comm_lst;
	t_token			*in_lst;
	t_token			*out_lst;
	struct s_pipe	*next;
	int				i_pipe;
}				t_pipe;

typedef struct s_shell
{
	char	*input;
	char	**envp_exec;
	t_token	*token_lst;
	t_pipe	*pipe_lst;
	int		pipes;
	int		exit_st;
}				t_shell;

/****************************** tokenizer.c ******************************/
t_operator	check_operator(char c);
int			handle_word(int i, char *input, t_token **token_lst);
int			handle_operator(char *input, int i, t_token **token_lst);
int			tokenizer(t_shell *shell);

/*************************** tokenizer_utils.c ***************************/
int			add_token(char *wd, t_operator op, t_token **token_lst);
t_token		*newtoken(char *wd, t_operator op);
int			tokenlst_size(t_token *token_lst);
void		tokenlst_addback_2(t_token **token_lst, t_token *new_token);

/**************************** check_quotes.c *****************************/
int			find_closing_quote(char *input, int i, int *qt_cnt, char qt);
int			check_quotes(t_shell *shell);
char		*strdup_unquoted(char *str);
void		strcopy_unquoted(char *dst, char *src, int dst_len, int src_len);
int			len_unquoted(char *str);

/******************************* parser.c ********************************/
int			parser(t_shell *shell);
void		set_pipe(t_pipe *pipe_lst, int cur_pipe, t_token **token_lst);
void		set_pipe_inlst(t_pipe *pipe_lst, t_token **token_lst);
void		set_pipe_outlst(t_pipe *pipe_lst, t_token **token_lst);
void		set_pipe_commlst(t_pipe *pipe_lst, t_token **token_lst);

/**************************** parser_utils.c *****************************/
int			count_pipes(t_token *token_lst);
t_pipe		*newpipe(int index);
t_pipe		*pipelst_last(t_pipe *pipe_lst);
void		pipelst_addback(t_pipe **pipe_lst, t_pipe *new_pipe);
void		tokenlst_addback(t_token **token_lst, t_token *new_token);

/********************** check_tokenlst_operators.c ***********************/
int			check_tokenlst_operators(t_shell *shell);

/****************************** expander.c *******************************/

char		*dollar_expand(char *str, t_shell *shell);
void		expander(t_shell *shell);

/*************************** expander_utils.c ****************************/

int			dollar_counter(char *str);
int			ft_isspecialchar(int c);
char		*ft_strdupsize(char *s1, size_t n);
void		my_strjoin(char **new_str, char **tmp);
void		my_srcdupsize(int i, int start, char *src, char **dst);

/*************************** expander_avoid_simplequotes.c ***************/
int			avoid_simplequotes(int i, char *str);

/**************************** matrix_utils.c *****************************/
char		**dup_matrix(char **matrix);
char		**tokenlst_to_matrix(t_token *token_lst);

/**************************** free_utils.c *******************************/
void		free_shell(t_shell *shell);
void		free_matrix(char **matrix);
void		free_tokenlst(t_token **token_lst);
void		free_pipelst(t_pipe **pipe_lst);

/**************************** executor_utils.c ***************************/
void		set_executor(t_shell *shell);
void		clean_quotes(t_shell *shell);

/*
 * Alberto
 */

/********************* 	main_getinput.c  *****************************/
void		get_input(t_shell *shell);

/********************* 	inc_shlvl_utils.c  ***************************/
int			isstrnum(char *str);
void		manager_shlvl_number(char *shlvl, int pos_shlvl, char **env);
void		change_set_shlvl_dup(char *strshlvl, int pos_shlvl, char **env);
void		add_set_shlvl_dup(char *strshlvl, char ***env);

/********************* inc_shlvl.c ***********************************/
void		inc_shlvl(char ***env);

/********************* bltin_env.c ***********************************/
void		bltin_env(char **env);

/********************* error_utils.c  **********************************/
int			error(char *m);
void		error_exit(char *m);
void		errorwrite(char *m);
int			error_three_str(char *str1, char *str2, char *str3);
int			error_four_str(char *str1, char *str2, char *str3, char *str4);

/********************* error_minish_perror_onetwoseven.c  ************/
void		minish_perror_onetwoseven(char *msg);

/********************* error_msg_exit.c  ************/
void		error_msg_exit(char *m);

/********************* executor_minish.c *****************************/
void		executor_minish(t_shell *shell);

/********************* set_path_cmd.c  *******************************/
int			set_path_cmd(t_pipe *pipe_node, char **env);

#endif
