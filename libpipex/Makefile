# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 23:21:56 by ekwak             #+#    #+#              #
#    Updated: 2023/01/01 14:59:03 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftpipex.a
BONUS = -DBONUS=1
AR = ar
ARFLAGS = -crs
RM = rm
RMFLAGS = -f
TEST = -Wall -Wextra -Werror -DDEBUGE=1 -DBONUS=1
SRCS =  create_commands.c \
		create_pipe_argument.c \
		get_path_directories.c \
		prepend_slash_to_command.c \
		validate_commands.c \
		ft_split_pipex.c \
		is_specified_path.c \
		ft_error.c \
		pipex.c \
		mandatory.c \
		bonus.c

OBJS = $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
				$(CC) $(CFLAGS) -c $(SRCS) -I./
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

bonus : $(OBJS)
			$(CC) $(CFLAGS) $(BONUS) -c $(SRCS) -I./
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

test : $(OBJS)
			$(CC) $(TEST) $(BONUS) -c $(SRCS) -I./
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean :
				$(RM) $(RMFLAGS) $(OBJS)

fclean : 
				$(RM) $(RMFLAGS) $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
