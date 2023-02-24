# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/02/20 16:34:42 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -g#-Werror

RM = rm -rf

libftFLAGS = -L./libft -lft

HEADERS = push_swap.h

SRCS =						sa.c \
							sb.c \
							ss.c \
							push_swap.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
			$(CC) $(libftFLAGS) $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJS) $(libft) Makefile
			$(MAKE) bonus -C libft
			$(CC) $(OBJS) -L./libft -lft -o $(NAME)


all	:		$(NAME)

clean :
			$(MAKE) clean -C libft
			$(RM) $(OBJS)

fclean :	clean
			$(MAKE) fclean -C libft
			$(RM) $(NAME)

re :		fclean all

.SILENT : $(OBJS) $(NAME)