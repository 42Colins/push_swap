# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/03/20 18:01:50 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -g #-Werror

RM = rm -rf

libftFLAGS = -L./libft -lft

HEADERS = push_swap.h

SRCS =						swap.c \
							push.c \
							push_swap.c \
							reverse_rotate.c \
							rotate.c \
							ft_atoll.c \
							check_errors.c \
							sort.c \
							utils.c \
							radix.c \

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