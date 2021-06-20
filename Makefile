# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 21:25:28 by dbutterw          #+#    #+#              #
#    Updated: 2021/06/09 21:25:28 by dbutterw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIRS		:= ./src
LIBFT_DIR		:=	./libft
LIBFT_INC_DIRS	:=	env avl char file graph hash_map list math memory num \
					string vector arr optparse regex error .
INC_FLAGS		:=	$(addprefix -I ,$(INC_DIRS)) $(addprefix -I , \
					$(addprefix $(LIBFT_DIR)/,$(LIBFT_INC_DIRS)))

SRC_DIR			:= ./src
SRCS			:= 	get_params.c											\
					handlers/handle_flt.c									\
					handlers/handle_chr.c									\
					handlers/handle_hex.c									\
					handlers/handle_int.c									\
					handlers/handle_nul.c									\
					handlers/handle_oct.c									\
					handlers/handle_ptr.c									\
					handlers/handle_str.c									\
					handlers/handle_uns.c									\
					printf.c												\
					utils/util_hexpref.c									\
					utils/util_print.c										\
					utils/util_rigor.c										\
					utils/util_sign.c										\
					utils/util_size.c										\
					utils/util_width.c

OBJ_DIR			:= ./obj
OBJS			:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

DEPS    		:= $(OBJS:.o=.d)

LIBFT			:= $(LIBFT_DIR)/libft.a
CFLAGS			:= -MMD -Wall -Wextra -Werror
NAME			:= libftprintf.a

.PHONY: all lib clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/handlers

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(CFLAGS) $(INC_FLAGS) -o $@ -c $<

-include $(DEPS)

$(NAME): $(OBJ_DIR) $(OBJS) | lib
	libtool -static -o $(NAME) $(LIBFT) $(OBJS)

lib:
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
