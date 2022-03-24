# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 11:00:24 by anruland          #+#    #+#              #
#    Updated: 2022/03/24 14:57:15 by anruland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config

NAME 	= push_swap
CC 		= gcc
CFLAGS	= -Werror -Wall -Wextra
LIBS	= -lft -lftprintf
LIB_DIR	= -L.

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

# Files

SRC		= ./*.c

all: $(NAME)

$(NAME): setup
	@echo "$(COM_COLOR)Compiling $(NAME)$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB_DIR) $(LIBS)
	@echo "$(OK_COLOR)Finished - usage: ./$(NAME) <list of non-duplicate numbers>$(NO_COLOR)"

setup:
	@echo "$(COM_COLOR)Compiling libft$(NO_COLOR)"
	@cd ./libft/ && make -s re
	@cp ./libft/libft.a ./
	@echo "$(COM_COLOR)Compiling ft_printf$(NO_COLOR)"
	@cd ./libftprintf/ && make -s re
	@cp ./libftprintf/libftprintf.a ./

clean:
# @echo "$(COM_COLOR)Cleaning Object Files$(NO_COLOR)"
# @/bin/rm -f

fclean: clean
	@echo "$(COM_COLOR)Cleaning $(NAME)$(NO_COLOR)"
	@/bin/rm -f $(NAME)

re: fclean all