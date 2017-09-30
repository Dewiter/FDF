# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 17:20:01 by rolevy            #+#    #+#              #
#    Updated: 2017/09/30 17:44:21 by rolevy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CC			= clang

FLAGS		= -framework OpenGL -framework AppKit
CFLAG		= -O3 -Wall -Werror -Wextra

PATH_SRC	= script/
PATH_INC	= includes/
PATH_MAPS	= Maps/

PATH_LIB	= ./source/libft/
PATH_GNL	= source/GNL/
PATH_MLX	= source/minilibx

VPATH = $(PATH_SRC):$(PATH_MAPS):$(PATH_INC)

SHELL = /bin/sh

SRC = Bresenham.c

SRC_O = $(SRC:.c=.o)
ARG_O = $(addprefix $(PATH_MAPS),$(notdir $(SRC:.c=.o)))

KO = "\033[34m[\033[31m ✘ \033[34m] "
OK = "\033[34m[\033[36m ✓ \033[34m] "
HD = "\033[34m[\033[35mFDF\033[34m] "
RM = "\033[1A\033[K"

vpath %.c $(PATH_SRC)
vpath %.o $(PATH_MAPS)
vpath %.h $(PATH_INC)


$(NAME): $(SRC_O)
	@make -C libft
	@printf $(OK)"> \033[36mGenrating binary...\033[0m\n"
	@$(CC) -o $(NAME) $(PATH_GNL)get_next_line.c $(PATH_LIB)libft.a \
		$(PATH_MLX)libmlx.a $(ARG_O) $(FLAGS) $(CFLAG)
	@if [ $$? ]; \
	then \
		printf "\033[34m[\033[35mSUCCESS\033[34m] \033[32mBin generated!\n\033[0m"; \
	else \
		printf $(KO); \
	fi;

all: $(NAME)

%.o: %.c | $(PATH_MAPS)
	@$(CC) -o $(PATH_MAPS)$@ -c $< $(CFLAG)
	@if [ $$? ]; \
	then \
		printf $(HD)$(OK)"\033[32m$@ \033[0m\n"; \
	else \
		printf "\033["; \
		printf $(HD)$(KO)"\033[90m* \033[36m$@\n"; \
	fi;

$(PATH_MAPS):
	@mkdir $@

clean:
	@rm -f $(ARG_O)
	@printf $(HD)$(OK)"\033[32mFiles cleaned\n"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@printf $(HD)$(OK)"\033[32mBinary cleaned\n"

re: fclean all
