# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 13:53:18 by apardo-m          #+#    #+#              #
#    Updated: 2024/05/31 10:21:50 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	minishell

SRCS_PROJECT := array_chang_val_pos.c \
			array_del_pos.c \
			array_getposstr.c \
			array_str_add.c \
			array_utils.c \
			bltin_env.c \
			builtin_cd_alb.c \
			builtin_cd_sets.c \
			builtin_check.c \
			builtin_echo_alb.c \
			builtin_exit.c \
			builtin_export_manage_onetwo.c \
			builtin_export_setoption.c \
			builtin_export_alb.c \
			builtin_pwd_alb.c \
			builtin_unset_alb.c \
			builtin_util_env_valid_name.c \
			check_quotes.c \
			check_tokenlst_operators.c \
			executor_utils.c \
			expander.c \
			expander_avoid_simplequotes.c \
			expander_utils.c \
			env_del_oldpwd.c \
			error_minish_perror_onetwoseven.c \
			error_msg_exit.c \
			error_utils.c \
			execute_utils.c \
			executor_execute_one_builtin.c \
			executor_getlastforkexitvalue.c \
			executor_init_files_execvars.c \
			executor_init_execvars.c \
			executor_minish.c \
			executor_set_execvars_tonextstep.c \
			executor_setsdtin.c \
			executor_setsdtout.c \
			fdmanager.c \
			free_utils.c \
			ft_getenv.c \
			heredocs.c \
		   	heredocs_utils.c \
			inc_shlvl.c \
			inc_shlvl_utils.c \
			main_minishell.c \
   			main_getinput.c \
			manager_returnwaitstatus.c \
		   	matrix_utils.c \
			parser.c \
		   	parser_utils.c \
			read_heredocs.c \
			seq_getlastforkexitvalue.c \
			set_path_cmd.c \
			setfileinfileout.c \
			signal_utils.c \
		   	test_fd_ok.c \
			tokenizer.c \
			tokenizer_utils.c

SRC_DIR := src

SRC		:=  $(addprefix $(SRC_DIR)/, $(SRCS_PROJECT))

OBJ_DIR:= objs

OBJ		:= $(addprefix $(OBJ_DIR)/, $(SRCS_PROJECT:.c=.o))

HEADER	:=	./inc/minishell.h ./inc/executor.h
LIBFT	:=	./lib/libft/libft.a
LIBRL	:=	./lib/readline/libreadline.a
RL_DIR  =  ./lib/readline/
READLINE	= $(RL_DIR)libreadline.a $(RL_DIR)libhistory.a

CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra #-fsanitize=address #-g

.PHONY	:	all clean fclean re

all	:
	@make --no-print-directory rl
	@echo
	@make --no-print-directory -C ./lib/libft
	@echo
	@make --no-print-directory $(NAME)

rl: 
	@if [ ! -f $(RL_DIR)config.status ] ; then \
		printf "\tConfiguring READLINE... " && \
		cd $(RL_DIR) && \
		./configure &> /dev/null && \
		echo OK; \
	fi
	@printf "\tMaking READLINE... "
	@cd $(RL_DIR) && make &> /dev/null
	@echo OK

$(NAME)	:	$(LIBFT) $(LIBRL) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Iinc -Ilib/libft -Ilib/readline -Llib/libft \
		-Llib/readline -lft -lreadline -lhistory -ltermcap $(CFLAGS)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c Makefile $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -Iinc -Ilib/libft -Ilib/readline -c $< -o $@

$(LIBFT):
	make -C ./lib/libft
	@echo
clean	:
	rm -rf $(OBJ_DIR)

fclean	:	clean
	@make --no-print-directory -C ./lib/libft fclean
	rm -f ./$(NAME)
	rm -rf ./$(NAME).dSYM

re		:	fclean all
