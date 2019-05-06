# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 15:08:21 by ssettle           #+#    #+#              #
#    Updated: 2019/05/06 13:33:44 by ssettle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c \
	dispatch_table.c \
	options.c \

CONVERT = convert_char.c \
	convert_float.c \
	convert_hex.c \
	convert_int.c \
	convert_octal.c \
	convert_pointer.c \
	convert_str.c \
	convert_uint.c \
	convert_upper_hex.c \
	convert_upper_uint.c

LIBFT_SRCS = ft_atoi.c \
	ft_lstdel.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strsplit.c \
	ft_bzero.c \
	ft_lstdelone.c \
	ft_memset.c \
	ft_strclr.c \
	ft_strmap.c \
	ft_strstr.c \
	ft_isalnum.c \
	ft_lstiter.c \
	ft_putchar.c \
	ft_strcmp.c \
	ft_strmapi.c \
	ft_strsub.c \
	ft_isalpha.c \
	ft_lstmap.c \
	ft_putchar_fd.c \
	ft_strcpy.c \
	ft_strncat.c \
	ft_strtrim.c \
	ft_isascii.c \
	ft_lstnew.c \
	ft_putendl.c \
	ft_strdel.c \
	ft_strncmp.c \
	ft_tolower.c \
	ft_isdigit.c \
	ft_memalloc.c \
	ft_putendl_fd.c \
	ft_strdup.c \
	ft_strncpy.c \
	ft_toupper.c \
	ft_isprint.c \
	ft_memccpy.c \
	ft_putnbr.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_wordcount.c \
	ft_isspace.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_striter.c \
	ft_strnew.c \
	ft_wordlen.c \
	ft_itoa.c \
	ft_memcmp.c \
	ft_putstr.c \
	ft_striteri.c \
	ft_strnlen.c \
	ft_itoa_base.c \
	ft_memcpy.c \
	ft_putstr_fd.c \
	ft_strjoin.c \
	ft_strnstr.c \
	ft_lstadd.c \
	ft_memdel.c \
	ft_strcat.c \
	ft_strlcat.c \
	ft_strrchr.c

OBJECTS =

FLAGS = -Wall -Werror -Wextra

INCLUDES = includes/

all: $(NAME)

$(NAME):
	make -C ./libft
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
