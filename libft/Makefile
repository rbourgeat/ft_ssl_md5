# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:35:27 by rbourgea          #+#    #+#              #
#    Updated: 2023/12/19 13:59:44 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 🎨 COLORS
# **************************************************************************** #

GREY    	=	\033[030m
RED     	=	\033[031m
GREEN   	=	\033[032m
YELLOW  	=	\033[033m
BLUE    	=	\033[034m
MAGENTA 	=	\033[035m
CYAN		=	\033[036m
BOLD		=	\033[1m
RESET   	=	\033[0m

# **************************************************************************** #
# 💾 VARIABLES
# **************************************************************************** #

NAME		=	libft.a
HEADER		=	libft.h

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

DIR_SRC		=	src
DIR_OBJ		=	obj
DIR_SUB		=	gnl \
				is \
				lst \
				malloc_free \
				mem \
				put \
				str \
				to

INCLUDE		= 	include/

SRC_DIR		=	$(foreach dir, $(DIR_SUB), $(addprefix $(DIR_SRC)/, $(dir)))
OBJ_DIR		=	$(foreach dir, $(DIR_SUB), $(addprefix $(DIR_OBJ)/, $(dir)))

SRC			=	$(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ			=	$(subst $(DIR_SRC), $(DIR_OBJ), $(SRC:.c=.o))

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

LIBC		=	ar -rcs

SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

# **************************************************************************** #
# 📖 RULES
# **************************************************************************** #

$(NAME):	$(OBJ)
			@$(LIBC) $(NAME) $(OBJ)
			@echo "$(BOLD)$(GREEN)[✓] $(NAME) BUILD DONE$(RESET)"

$(OBJ): 	| $(OBJ_DIR)

$(OBJ_DIR):
			@mkdir -p $(DIR_OBJ) $(OBJ_DIR)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c ${INCLUDE}${HEADER} Makefile
				@${CC} ${CFLAGS} -I ${INCLUDE} -o $@ -c $<

all			:	$(NAME)  

clean		:
				@$(RM_DIR) $(DIR_OBJ)
				@echo "$(BOLD)$(RED)[♻︎] DELETE LIBFT OBJS DONE$(RESET)"

fclean		:	clean
				@$(RM_FILE) $(NAME)
				@echo "$(BOLD)$(RED)[♻︎] DELETE $(NAME) DONE$(RESET)"

re			:	fclean all

.PHONY		: all clean fclean re bonus
