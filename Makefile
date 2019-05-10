# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 15:08:21 by ssettle           #+#    #+#              #
#    Updated: 2019/05/09 20:16:43 by ssettle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NEW_DIR = mkdir -p $(@)

SRC_DIR = ./sources/
INC_DIR = ./includes/
CNVT_DIR = ./convertions/
OBJ_DIR = ./objects/

SRCS = $(addprefix $(SRC_DIR),$(SOURCES))
INC = $(addprefix -I,$(INC_DIR))
CNVT = $(addprefix $(CNVT_DIR),$(CONVERT))
OBJS = $(addprefix $(OBJ_DIR),$(OBJECTS))

SOURCES = sources/ft_printf.c \
	sources/dispatch_table.c \
	sources/dispatch_conv.c \
	sources/options.c \

CONVERT = convert_char.c \
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

#TOOLS =

OBJECTS = $(SOURCES:.c=.o),$(CONVERT:.c=.o)

FLAGS = -Wall -Werror -Wextra

INCLUDES = includes/

all: $(NAME)

$(NAME):
	@make -C ./libft
	@echo Made the libft!
	@gcc $(FLAGS) -c $(SOURCES) -I $(INCLUDES)
	@gcc $(FLAGS) -o $(NAME)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo Project made!

clean:
	@make -C ./libft clean
	@rm -rf $(OBJECTS)
	@echo Project cleaned!

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@echo Project fcleaned!

re: clean all

.PHONY: make, all, clean, fclean, re, test
