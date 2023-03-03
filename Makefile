# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 19:07:58 by clbernar          #+#    #+#              #
#    Updated: 2023/03/01 16:25:55 by clbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS = push_swap.c utils_list.c check_list.c fill_list.c get_closer.c moves.c family_move.c sort.c

LIB = $(LIBFT_PATH)/libft.a
LIBFT_PATH = ./Libft

OBJS = $(SRCS:.c=.o)

INC = $(LIBFT_PATH)

all : $(NAME)

$(NAME) : $(LIB) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

%.o : %.c
	$(CC) -I$(INC) $(CFLAGS) -c $<

$(LIB):
	make -C Libft/
	make bonus -C Libft/

clean:
	$(RM) $(OBJS) $(B_OBJS)
	make fclean -C Libft/

fclean: clean
	 $(RM) $(NAME)

re: fclean all

.PHONY : re all fclean bonus clean
