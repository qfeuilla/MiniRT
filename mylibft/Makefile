# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 11:56:45 by qufeuill          #+#    #+#              #
#    Updated: 2019/11/28 14:39:57 by qfeuilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I libft.h
FILES = ft_atoi.c \
	    ft_calloc.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_toupper.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_substr.c	\
		ft_putstrfree.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstsize.c \
		ft_lstadd_front.c \
		ft_lstdelone.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_hex_len.c \
		ft_int_len.c \
		ft_memalloc.c \
		ft_printhex.c \
		ft_abs.c \
		ft_c_in_s.c \
		get_next_line.c \
		ft_printf_flags.c \
		ft_printf.c \
		parser.c \
		ft_count_params.c \
		ft_uint.c \
		ft_int.c \
		ft_char.c \
		ft_string.c \
		ft_ptr.c \
		ft_hex.c \
		print_width.c \
		wrong_manager.c \
		ft_perc_manager.c \
		ft_pow.c

OBJ = $(FILES:.c=.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	@rm -f $(NAME) $(BN)

re: fclean all

.PHONY: clean fclean re all