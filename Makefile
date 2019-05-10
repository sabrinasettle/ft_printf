# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 15:08:21 by ssettle           #+#    #+#              #
#    Updated: 2019/05/10 09:54:34 by ssettle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


SOURCES = ft_printf \
	dispatch_table \
	# sources/dispatch_conv.c \
	# sources/options.c \
	# sources/val_flag.c \

CONVERT = conversions/convert_char \
	# convert_float.c \
	# convert_hex.c \
	# convert_int.c \
	# convert_octal.c \
	# convert_pointer.c \
	# convert_str.c \
	# convert_uint.c \
	# convert_upper_hex.c \
	conversions/convert_upper_uint.c \
	conversions/convert_percent.c \

TOOLS = tools/pf_putchar.c \
	# tools/pf_atoi.c

VPATH=conversions:includes:sources:tools
OBJECTS = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SOURCES)))
# OBJECTS += $(patsubst %.c,%.o,$(CONVERT))
# OBJECTS += $(patsubst %.c,%.o,$(TOOLS))

# $(add_suffix .o, $(addprefix $(OBJ_DIR)/, $(SOURCES))

FLAGS = -Wall -Werror -Wextra

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
