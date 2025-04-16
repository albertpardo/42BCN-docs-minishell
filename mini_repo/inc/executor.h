/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:59:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:17 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <fcntl.h>
# include "minishell.h"

# define PIPE0_STDIN 0
# define PIPE1_STDOUT 1

# define TEMP_FILE_NAME "/tmp/.tmp_heredoc"

# define TRUE 1
# define FALSE 0

# define MINI "minishell: "
# define NO_IDENTIFIER "': not a valid identifier"
# define NO_EXECVE "Could not execute execve"
# define PROBLEMS_EXECVE "---> TODO: Define error MSG for problems with EXECVE"
# define NO_NEW_FORK "-- Error : No new fork "
# define ERROR_HERE_OPEN "heredocs -> open() failed\n"
# define ERROR_HERE_CLOSE "heredocs -> Close error\n"
# define ERROR_HERE_EXEC "problemas al ejecutar HEREDOC\n"
# define ERROR_HERE_FORK "Error Fork para heredocs emulation\n"
# define ERROR_FILEOUT_OPEN "fileout \">\" -> open() failed\n"
# define ERROR_FILEOUT_CLOSE "fileout \">\" -> close() failed\n"
# define ERROR_MALLOC "SYSTEM ERROR -> MALLOC ERROR"
# define ERROR_ADD_ENV "Error add VARNAME in env\n"
# define ERROR_UNSET "UNSET -> NO valid VARNAME (TODO errno like BASH)"

typedef struct s_execut
{
	int		fdin;
	int		tmp_in;
	int		tmp_out;
	int		fdout;
	int		next_fdin;
	int		next_pipe[2];
	char	*filein;
	char	*fileout;
	int		isfileoutappend;
}	t_execut;

/********************* array_del_pos.c *******************************/
char		**rmposarr(char **arr, int pos);

/********************* array_getposstr.c *****************************/
int			getposstr(char **arr, char *substr);

/********************* array_str_add.c *******************************/
void		add_new_var(char ***env, char *str);

/********************* array_chang_val_pos.c *************************/
void		change_value_pos(char **arr, int pos, char *str);

/********************* env_del_oldpwd.c ******************************/
void		reset_oldpwd(char ***env);
char		**env_del_oldpwd(char **env);

/********************* array_utils.c *********************************/
int			sizearr(char **arr);
void		free_arr_content(char **arr);
void		cp_except_pos(char **dest, char **ori, int pos);
void		cp_arr(char **dest, char **ori, int n_elem);
char		**addstrarr(char **arr, char *str);

/********************* executor_init_files_execvars.c ****************/
void		init_files_execvars(t_execut *vars);

/********************* executor_init_execvars.c **********************/
void		init_execvars(t_execut *vars);

/********************* executor_set_execvars_tonextstep.c ************/
void		set_execvars_tonextstep(t_execut *execvars);

/********************* executor_setsdtin.c **************************/
void		setsdtin(t_execut *execvars);

/********************* executor_setsdtout.c **************************/
void		setsdtout(t_execut *execvars);

/********************* executor_getlastforkexitvalue.c ***************/
int			getlastforkexitvalue(int npipes, int lastpid);

/********************* seq_getlastforkexitvalue.c ***************/
int			seq_getlastforkexitvalue(int npipes, pid_t *pids);

/********************* executor_execute_one_builtin.c ****************/
int			execute_one_builtin(t_shell *shell);

/********************* manager_returnwaitstatus.c ********************/
int			manager_returnwaitstatus(const int status);

/********************* execute_utils.c *******************************/
pid_t		execute(t_execut *evars, t_pipe *pnode, t_shell *shell);

/********************* read_heredocs.c *******************************/
char		*next_heredoc_filename(int i);
int			read_heredocs(t_shell *shell);

/********************* heredocs.c ************************************/
int			emula_here_docs(char *filename, char *str_limit, t_shell *shell);

/********************* heredocs_utils.c ******************************/
void		del_tmp_files_heredocs(char *file);
void		free_heredoc_file_name(char *file);

/********************* signal_utils.c ********************************/
void		signals_print_handler(int print);
void		stop_signals(void);
void		set_defaultsignals_fork(void);
void		signals_minishell(void);

/********************* test_fd_ok.c  *********************************/
int			test_fd_ok(int fd, char *m);

/********************* setfileinfileout.c  ***************************/
int			setfileinfileout(t_pipe *pnode, t_execut *execvars, int i);

/********************* fdmanager.c  **********************************/
int			fdmanager(t_pipe *pnode, t_execut *execvars);

/********************* builtin_util_env_valid_name.c  ****************/
int			isvalidvarname(const char *str);

/********************* builtin_check.c  ******************************/
int			get_builtin(char *comm);
// int			exec_builtin(int bltnum, char **argv_exec, char ***env);
int			exec_builtin(int bltnum, char **argv_exec, t_shell *shell);

/********************* builtin_echo_alb.c  ***************************/
void		builtin_echo(char **argv);

/********************* builtin_pwd_alb.c  ****************************/
int			builtin_pwd(void);

/********************* builtin_export_setoption.c  *******************/
int			setoption(char **varname, int *option, char *arg);

/********************* builtin_export_manage_onetwo.c  ***************/
void		manage_onetwo(int option, char *varname, char *arg, char ***env);

/********************* builtin_export_alb.c **************************/
int			builtin_export(char **argv, char ***env);

/********************* builtin_unset_alb.c ***************************/
int			builtin_unset(char **argv, char ***env);

/********************* builtin_cd_sets.c *****************************/
void		set_varname(char *varname, char *value, char ***env);
void		set_pwd_oldpwd(char *old_pwd, char *pwd, char ***env);

/********************* builtin_cd_alb.c ******************************/
int			builtin_cd(char **argv, char ***envp);

/********************* builtin_exit.c ********************************/
void		builtin_exit(char **argv_exec, t_shell *shell);

/********************* builtin_exit_alb.c ****************************/
//void		builtin_exit(char **argv_exec);

/********************* ft_getenv.c ***********************************/
char		*ft_getenv(char **arr, char *substr);

#endif
