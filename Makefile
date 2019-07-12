# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 15:08:21 by ssettle           #+#    #+#              #
#    Updated: 2019/07/11 20:16:38 by ssettle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf \
	dispatch_table \
	dispatch_conv \
	options \
	val_flag \

CONVERT = convert_char \
	# convert_str \
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


TOOLS = pf_putchar \
	pf_atoi \
	pf_strlen \

VPATH=conversions:includes:srcs:tools:padding
OBJECTS = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SOURCES)))
OBJECTS += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(CONVERT)))
OBJECTS += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(TOOLS)))
# OBJECTS += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(PADDING)))

# $(add_suffix .o, $(addprefix $(OBJ_DIR)/, $(SOURCES))

FLAGS = -Wall -Werror -Wextra -g

INCLUDES = includes/ft_printf.h

OBJ_DIR = objects

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:%.c
	@gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS)
	@ar -rcs $@ $^
	@echo Library made!

clean:
	@rm -rf $(OBJECTS)
	@echo Project cleaned!

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo Project fcleaned!

re: clean all

.PHONY: make, all, clean, fclean, re, test
