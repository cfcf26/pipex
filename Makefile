# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 21:10:54 by ekwak             #+#    #+#              #
#    Updated: 2022/12/30 21:51:31 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
BONUS = -DBUNUS=1
DFLAGS = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
TEST = -Wall -Wextra -Werror -DDEBUGE=1

RM = rm
RMFLAGS = -f
SRCS =  ./libft/libft.a \
		./gnl/libftgnl.a \
		./libpipex/libftpipex.a \

all : $(NAME)

$(SRCS) :
	make -C ./libft all
	make -C ./gnl all
	make -C ./libpipex all

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS)

test :
	make -C ./libft all
	make -C ./gnl all
	make -C ./libpipex test
	$(CC) $(TEST) -o $(NAME) main.c $(SRCS)

bonus :
	make -C ./libft all
	make -C ./gnl all
	make -C ./libpipex bonus
	$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS)

debug :
	$(CC) $(CFLAGS) $(DFLAGS) -o $(NAME) main.c $(SRCS)

clean :
	make -C ./libft clean
	make -C ./gnl clean
	make -C ./libpipex clean

fclean : 
	make -C ./libft fclean
	make -C ./gnl fclean
	make -C ./libpipex fclean
	$(RM) $(RMFLAGS) $(NAME)

run :
	$(RM) $(RMFLAGS) $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).c $(SRCS)

re : fclean all

.PHONY : all clean fclean re debug