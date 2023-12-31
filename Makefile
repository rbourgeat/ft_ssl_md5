# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 12:40:33 by rbourgea          #+#    #+#              #
#    Updated: 2023/12/19 16:22:21 by rbourgea         ###   ########.fr        #
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

NAME		=	ft_ssl

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb -fsanitize=address

INCLUDE		= 	include/
LIBFT_DIR	=	./libft
SRC_DIR		=	src
OBJ_DIR		=	obj

LIBFT_LIB	=	libft.a

SRC			=	ft_ssl.c \
				ft_ssl_read_hash_file.c \
				ft_ssl_print.c \
				parsing/parsing.c \
				parsing/parsing_argv.c \
				md5/md5.c \
				md5/md5_algorithm.c \
				sha256/sha256.c \
				sha256/sha256_algorithm.c \
				sha256/sha256_utily.c \
				sha256/sha256_utily2.c \
				sha512/sha512.c \
				sha512/sha512_algorithm.c \
				sha512/sha512_utily.c \
				sha512/sha512_utily2.c

OBJ			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(@D)
				$(CC) $(FLAGS) -c -o $@ $< -I $(INCLUDE)

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

#DEBUG
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

# **************************************************************************** #
# 📖 RULES
# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT_DIR) all
			@$(CC) -o $(NAME) $(FLAGS) $^ $(LIBFT_DIR)/$(LIBFT_LIB)
			@echo "$(BOLD)$(GREEN)[✓] $(NAME) BUILD DONE$(RESET)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(FLAGS) -c -o $@ $< -I $(INCLUDE)

clean:
			@make -C ${LIBFT_DIR}/ clean
			@${RM_DIR} ${OBJ_DIR}
			@echo "$(BOLD)$(RED)[♻︎] DELETE $(NAME) OBJS DONE$(RESET)"

fclean:
			@make -C ${LIBFT_DIR}/ fclean
			@${RM_DIR} ${OBJ_DIR}
			@${RM_FILE} $(NAME)
			@echo "$(BOLD)$(RED)[♻︎] DELETE $(NAME) DONE$(RESET)"

re:			fclean all

.PHONY: all clean fclean re bonus

MAKEFLAGS += --no-print-directory
MAKEFLAGS += --no-warn-undefined-variables
