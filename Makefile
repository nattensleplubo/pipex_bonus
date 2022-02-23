# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 18:52:30 by ngobert           #+#    #+#              #
#    Updated: 2022/02/23 11:50:53 by ngobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS		=	pipex.c utils.c more_utils.c run_mid.c pipe.c run_first.c run_last.c
OBJS		=	$(SRCS:.c=.o);

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -I.

LIB_PATH = ./libft/libft.a

all:		$(NAME)

$(NAME): $(OBJS)
		make -C libft/ bonus
		$(CC) $(CFLAGS) $(SRCS) $(LIB_PATH) -o $(NAME)

clean:
			make -C libft/ clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make -C libft/ fclean

re:			fclean $(NAME)
