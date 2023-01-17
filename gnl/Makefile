# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 23:21:56 by ekwak             #+#    #+#              #
#    Updated: 2022/11/24 17:00:00 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftgnl.a
AR = ar
ARFLAGS = -crs
RM = rm
RMFLAGS = -f
SRCS =  get_next_line_utils.c \
		get_next_line.c

OBJS = $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
				$(CC) $(CFLAGS) -c $(SRCS) -I./
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
				$(RM) $(RMFLAGS) $(OBJS)

fclean : 
				$(RM) $(RMFLAGS) $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
