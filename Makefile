# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 15:08:21 by ssettle           #+#    #+#              #
#    Updated: 2019/07/18 16:32:12 by ssettle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf \
	dispatch_table \
	dispatch_conv \
	val_flag \
	options \
	parse \

CONVERT = convert_char \
	convert_str \
	# convert_percent \
	# convert_octal \
	# convert_float \
	convert_pointer \
	# convert_hex \
	# convert_int \
	# convert_octal \
	convert_str.c \
	# convert_uint.c \
	# convert_upper_hex.c \
	convert_upper_uint.c \


# PADDING = pad_pointer \
	# padding/pad_int.c \
	# padding/pad_octal.c \
	padding/pad_pointer.c \
	# padding/pad_uint.c


SOURCES_D = ./srcs
CONVER_D = ./conversions
PAD_D = ./padding

OBJECTS = $(addsuffix .o, $(addprefix $(SOURCES_D)/, $(SOURCES)))
OBJECTS += $(addsuffix .o, $(addprefix $(CONVER_D)/, $(CONVERT)))
OBJECTS += $(addsuffix .o, $(addprefix $(PAD_D)/, $(PADDING)))

FLAGS = -Wall -Werror -Wextra -g

INCLUDES = includes/ft_printf.h

LIBFT = $(addprefix $(LIBFT_D),libft.a)
LIBFT_D = ./libft/

# OBJ_DIR = objects

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_D)

# $(OBJ_DIR)/%.o:%.c
# 	@gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJECTS)
	@ar -rcs $@ $^
	@echo =====Library made!=====

clean:
	@rm -rf $(OBJECTS)
	@echo *==Project cleaned!===*

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_D)
	@echo  *==Project fcleaned!==*

re: clean all

.PHONY: make, all, clean, fclean, re, test
