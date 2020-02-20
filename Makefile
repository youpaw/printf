#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbutterw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 14:53:41 by dbutterw          #+#    #+#              #
#    Updated: 2019/09/27 15:08:06 by dbutterw         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_DIR := ./src
INC_DIR := -I includes                             \
            -I libft                               \
            -I src/handlers/floats/bigint          \
            -I src/handlers/floats/doubleunpacked  \
            -I src/handlers/floats/printdouble     \
            -I src/handlers/floats/str             \
            -I src/handlers/floats/unpackdouble    \
            -I src/handlers/floats/utils
OBJ_DIR := ./obj

SRC		:=	ft_get_params.c				\
			ft_printf.c					\
			handlers/ft_handle_chr.c	\
			handlers/ft_handle_hex.c	\
			handlers/ft_handle_int.c	\
			handlers/ft_handle_nul.c	\
			handlers/ft_handle_oct.c	\
			handlers/ft_handle_ptr.c	\
			handlers/ft_handle_str.c	\
			handlers/ft_handle_uns.c	\
			utils/ft_util_handle.c		\
			utils/ft_util_hexpref.c		\
			utils/ft_util_print.c		\
			utils/ft_util_rigor.c		\
			utils/ft_util_sign.c		\
			utils/ft_util_size.c		\
			utils/ft_util_width.c		\
			handlers/floats/bigint/big_int_arithmetics.c			\
			handlers/floats/bigint/big_int_helper.c					\
			handlers/floats/bigint/big_int_operatoins.c				\
			handlers/floats/bigint/big_int_print.c					\
			handlers/floats/doubleunpacked/print_double_unpacked.c	\
			handlers/floats/printdouble/print_double.c				\
			handlers/floats/str/str.c								\
			handlers/floats/unpackdouble/unpack_double1.c			\
			handlers/floats/unpackdouble/unpack_double2.c			\
			handlers/floats/unpackdouble/double_classifier1.c		\
			handlers/floats/unpackdouble/double_classifier1.c		\
			handlers/floats/unpackdouble/double_representation.c	\
			handlers/floats/utils/utils.c							\
			handlers/floats/ft_handle_flt.c


OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CFLAGS	:= -Wall -Wextra -Werror -DDOUBLE_EXTENDED=1

NAME	:= libftprintf.a

.PHONY: all clean lib fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/handlers
	mkdir -p $(OBJ_DIR)/handlers/floats
	mkdir -p $(OBJ_DIR)/handlers/floats/bigint
	mkdir -p $(OBJ_DIR)/handlers/floats/doubleunpacked
	mkdir -p $(OBJ_DIR)/handlers/floats/printdouble
	mkdir -p $(OBJ_DIR)/handlers/floats/str
	mkdir -p $(OBJ_DIR)/handlers/floats/unpackdouble
	mkdir -p $(OBJ_DIR)/handlers/floats/utils

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | lib
	gcc $(CFLAGS) $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) | lib
	ar rcs $(NAME) $(OBJ) ./libft/*.o

lib:
	make -C ./libft

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
