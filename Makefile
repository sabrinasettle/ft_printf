# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 15:08:21 by ssettle           #+#    #+#              #
#    Updated: 2019/05/10 09:09:33 by ssettle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = sources/ft_printf.c \
	sources/dispatch_table.c \
	sources/dispatch_conv.c \
	sources/options.c \
	sources/val_flag.c \

CONVERT = convertions/convert_char.c \
	convert_float.c \
	convert_hex.c \
	convert_int.c \
	convert_octal.c \
	convert_pointer.c \
	convert_str.c \
	convert_uint.c \
	convert_upper_hex.c \
	convert_upper_uint.c \
	convert_percent.c \

TOOLS = tool_funcs/pf_putchar.c \
	tool_funcs/

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
OBJECTS += $(patsubst %.c,%.o,$(CONVERT))
OBJECTS += $(patsubst %.c,%.o,$(TOOLS))


FLAGS = -Wall -Werror -Wextra

INCLUDES = includes/ft_printf.h

all: $(NAME)

	# gcc $(FLAGS) -c $(SOURCES) $(CONVERT) -I $(INCLUDES)

$(NAME): $(OBJECTS)
	# @make -C ./libft
	# @echo Made the libft!
	# @gcc $(FLAGS) -c $(SOURCES) -I $(INCLUDES)
	# @gcc $(FLAGS) -o $(NAME)
	@gcc $(FLAGS) -c $(SOURCES) $(CONVERT) $(TOOLS) -I $(INCLUDES)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo Library made!

clean:
	# @make -C ./libft clean
	@rm -rf $(OBJECTS)
	@echo Project cleaned!

fclean: clean
	# @make -C ./libft fclean
	@rm -f $(NAME)
	@echo Project fcleaned!

re: clean all

.PHONY: make, all, clean, fclean, re, test
