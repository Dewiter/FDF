# ************************************************************************************* #
#                                                                              			#
#                                                         :::      ::::::::    			#
#    Makefile                                           :+:      :+:    :+:    			#
#                                                     +:+ +:+         +:+      			#
#    By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+         			#
#                                                 +#+#+#+#+#+   +#+            			#
#    Created: 2017/10/01 12:39:14 by rolevy            #+#    #+#              			#
#    Updated: 2017/10/01 13:56:48 by rolevy           ###   ########.fr        #
#                                                                              			#
# ************************************************************************************* #


# ===================================================================================== #
#								   Variable												#
# ===================================================================================== #

NAME		= fdf

CC			= clang
FRAMEWORK	= -framework OpenGL -framework Appkit

SRC			=	bresenham.c	\
				main.c		\
				env.c		

INC			= fdf.h

PATH_SRC	= src/
PATH_INC	= includes/
PATH_LIB	= source/libft/
PATH_MLX	= source/minilibx/
PATH_DUMP	= dump/

MAKE_LIB 	= 1

SRC_O = $(SRC:.c=.o)
ARG_O = $(addprefix $(PATH_DUMP),$(notdir $(SRC:.c=.o)))

# ===================================================================================== #
#									Strings												#
# ===================================================================================== #

OK = "\033[34m[\033[36m ✓ \033[34m] "
KO = "\033[34m[\033[31m ✘ \033[34m] "
HD = "\033[34m[\033[95mFDF\033[34m] "

# ===================================================================================== #
#									Path												#
# ===================================================================================== #

vpath %.c $(PATH_SRC)
vpath %.o $(PATH_DUMP)
vpath %.h $(PATH_INC)

# ===================================================================================== #
#									Process												#
# ===================================================================================== #

$(NAME) : $(SRC_O) $(PATH_LIB)
	@make -C $(PATH_LIB)
	@printf $(OK)"> \033[36mGenrating binary...\033[0m\n"
	@$(CC) -o $(NAME) $(PATH_LIB)libft.a $(PATH_MLX)libmlx.a $(ARG_O) $(FRAMEWORK)
	@if [ $$? ]; \
	then \
		printf "\033[34m[\033[35mSUCCESS\033[34m] \033[32mBin generated!\n\033[0m"; \
	else \
		printf $(KO); \
	fi;

all : $(NAME)


%.o : %.c $(INC) $(PATH_DUMP)
	@$(CC) -c $< -o $(PATH_DUMP)$@
	@if [ $$? ];	\
	then 			\
		printf $(HD)$(OK)"\033[32m$@ \033[0m\n";	\
	else			\
		printf $(HD)$(KO)"\033[90m* \033[36m$@\n";	\
	fi;

$(PATH_DUMP) :
	@mkdir $@

clean :
	@if [ !$(MAKE_LIB) ];	\
	then					\
		make -C $(PATH_LIB) clean;	\
	fi;
	@rm -f $(ARG_O)
	@printf $(HD)$(OK)"\033[32mFiles cleaned\n"

fclean : clean
	@rm -f $(ARG_O)
	@if [ !$(MAKE_LIB) ];	\
	then					\
		make -C $(PATH_LIB) fclean;	\
	fi;
	@rm -f $(NAME)
	@printf $(HD)$(OK)"\033[32mBinary cleaned\n"

re : fclean all