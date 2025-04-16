/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:53:33 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/30 11:06:51 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/*
#define MAX_NOASCII_LINES 10

static void	check_nottylimit(char *input)
{
	static int	count = 0;

	if (!isatty(STDIN_FILENO))
	{
		if (input != NULL)
		{
			while (*input != '\0' && ft_isascii(*input))
				input++;
			if (!ft_isascii(*input) && count < MAX_NOASCII_LINES)
				count++;
			if (count == MAX_NOASCII_LINES)
				exit(EXIT_FAILURE);
		}
	}
	else
		count = 0;
}

static void	control_and_c(int *exit_status)
{
	if (g_signal == SIGINT)
	{
		*exit_status = EXIT_FAILURE;
		g_signal = 0;
	}
}

static void	check_ctrld(char *input, int exit_st)
{
	if (input == 0)
	{
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			ft_putendl_fd("\033[A\033[2KMINISHELL$ exit", STDERR_FILENO);
		else if (!isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			ft_putendl_fd("\033[2K\033[1A", STDERR_FILENO);
		exit (exit_st);
	}
}
*/

/*
 * Set initial values for 'shell' struct
 */

/*
void	init_shell(t_shell *shell)
{
	shell->envp_exec = 0;
	shell->input = 0;
	shell->token_lst = 0;
	shell->pipe_lst = 0;
	shell->pipes = 0;
	shell->exit_st = 0;
}
*/

static void	init_shell(t_shell *shell, char **envp)
{
	shell->envp_exec = dup_matrix(envp);
	shell->input = NULL;
	shell->token_lst = NULL;
	shell->pipe_lst = NULL;
	shell->pipes = 0;
	shell->exit_st = 0;
	reset_oldpwd(&shell->envp_exec);
	inc_shlvl(&shell->envp_exec);
}

/*
void	get_input(t_shell *shell)
{
	char	*trim_input;

//  init_shell(shell);
	shell->input = readline("MINISHELL$ ");
	if (shell->input == 0)
		exit (EXIT_FAILURE);
	if (shell->input && shell->input[0])
		add_history(shell->input);
	trim_input = 0;
	trim_input = ft_strtrim(shell->input, " ");
	free(shell->input);
	shell->input = trim_input;
	if (shell->input == 0)
		exit (EXIT_FAILURE);
}
*/

/*
 *	This function check if CTRL+C is pressed.
 *
 *  In this case "ANSI Escape Sequences" is used to put the line similar to BASH
 *  See : https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 *  Where :
 *  \033 is the octal value vor ESC
 *  [A	 moves cursor up 1 line
 * 	[2K	 erase the entire line
 * 	\r   Put the cursor to start current line 
 */
/*
void	get_input(t_shell *shell)
{
	char	*trim_input;

//	printf("\nNueva lectura CLI --------- \n");
	shell->input = readline("MINISHELL$ ");
//	printf("\nYour input -> %s\n", shell->input);
	check_nottylimit(shell->input);
	if (shell->input == 0)
	{
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			ft_putendl_fd("\033[A\033[2KMINISHELL$ exit", STDERR_FILENO);
		else if (!isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			ft_putendl_fd("\033[2K\033[1A", STDERR_FILENO);
		exit (shell->exit_st);
	}
	if (shell->input && shell->input[0])
		add_history(shell->input);
	control_and_c(&(shell->exit_st));
	trim_input = ft_strtrim(shell->input, " ");
	free(shell->input);
	shell->input = trim_input;
	if (shell->input == 0)
		exit (EXIT_FAILURE);
	rl_on_new_line();
	control_and_c(&(shell->exit_st));
}
*/
/*
void	get_input(t_shell *shell)
{
	char	*trim_input;

	signals_minishell();
	shell->input = readline("MINISHELL$ ");
	stop_signals();
	check_ctrld(shell->input, shell->exit_st);
	control_and_c(&(shell->exit_st));
	check_nottylimit(shell->input);
	if (shell->input && shell->input[0])
		add_history(shell->input);
	trim_input = ft_strtrim(shell->input, " ");
	free(shell->input);
	shell->input = trim_input;
	if (shell->input == 0)
		exit (EXIT_FAILURE);
	rl_on_new_line();
}
*/

/*
 *  TODO?? in line:
 *  if (!check_quotes(&shell) || shell.input[0] == '\0')
 *				free_shell(&shell);              //or just free(shell.input)
 */

/*
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	if (argc != 1 || argv[1])
		error_args("minishell: Please do not enter any arguments!");
	init_shell(&shell, envp);
	while (1)
	{
		get_input(&shell);
		if (shell.input[0] != '\0')
		{
			if (!check_quotes(&shell) || shell.input[0] == '\0')
				free_shell(&shell);
			else if (!tokenizer(&shell))
				free_shell(&shell);
			else if (!check_tokenlst_operators(&shell))
				free_shell(&shell);
			else if (!parser(&shell))
				free_shell(&shell);
			else
				executor_minish(&shell);
		}
	}
	free_shell(&shell);
	return (shell.exit_st);
}
*/

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	if (argc != 1 || argv[1])
		error_msg_exit("minishell: Please do not enter any arguments!");
	init_shell(&shell, envp);
	while (1)
	{
		get_input(&shell);
		if (shell.input[0] == '\0' || !check_quotes(&shell))
			free_shell(&shell);
		else if (!tokenizer(&shell))
			free_shell(&shell);
		else if (!check_tokenlst_operators(&shell))
			free_shell(&shell);
		else if (!parser(&shell))
			free_shell(&shell);
		else
			executor_minish(&shell);
	}
	free_shell(&shell);
	return (shell.exit_st);
}
