# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 08:48:02 by spereyra          #+#    #+#              #
#    Updated: 2023/12/02 13:02:03 by spereyra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
SRC			:=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c\
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
				ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
				ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
				ft_print_char.c ft_print_dec.c ft_print_format.c ft_printf.c\
				ft_print_ptr.c ft_print_str.c ft_print_xlo.c ft_print_xup.c\
				ft_atol.c ft_isspace.c
OBJ			:=	$(SRC:.c=.o)
INCLUDE		:=	libft.h ft_printf.h
CC			:=	gcc
CFLAGS		:=	-Wall -Werror -Wextra
RM			:=	rm -f

.PHONY	: all clean fclean re
all		: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	ar rcs $(NAME) $(OBJ)

%.o		: %.c Makefile $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re:	fclean all
