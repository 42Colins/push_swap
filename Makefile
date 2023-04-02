# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/04/02 20:05:55 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -rf

libftFLAGS = -L./libft -lft

HEADERS = push_swap.h

LIB = libft/libft.a

SRCS =						swap.c \
							push.c \
							push_swap.c \
							reverse_rotate.c \
							rotate.c \
							ft_atoll.c \
							check_errors.c \
							sort.c \
							radix.c \
							utils.c \
							big_parse.c

OBJS = $(SRCS:.c=.o)

%.o: %.c	$(LIB) $(HEADERS)
			$(CC) $(CFLAGS) -c $< -o $@

all	:		makelib $(NAME)

$(NAME) :	$(LIB) $(OBJS)
			$(CC) $(OBJS) -o  $(NAME) -L./libft -lft


makelib:
			$(MAKE) -C libft

clean :
			$(MAKE) clean -C libft
			$(RM) $(OBJS)

fclean :	clean
			$(MAKE) fclean -C libft
			$(RM) $(NAME)

re :		fclean all

# .SILENT : $(OBJS) $(NAME)
