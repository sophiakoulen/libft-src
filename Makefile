# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 10:31:58 by skoulen           #+#    #+#              #
#    Updated: 2022/10/11 10:32:04 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = ft_isalnum.o \
ft_isalpha.o \
ft_isascii.o \
ft_isdigit.o \
ft_isprint.o \
ft_bzero.o \
ft_memcpy.o \
ft_memmove.o \
ft_memset.o \
ft_strlen.o \
ft_strlcat.o \
ft_strlcpy.o \
ft_tolower.o \
ft_toupper.o \
ft_strchr.o \
ft_strrchr.o \
ft_strncmp.o \
ft_memcmp.o \
ft_memchr.o \
ft_strnstr.o \
ft_atoi.o \
ft_calloc.o \
ft_strdup.o \
ft_substr.o \
ft_strjoin.o \
ft_strtrim.o \
ft_itoa.o \
ft_strmapi.o \
ft_striteri.o \
ft_putchar_fd.o \
ft_putstr_fd.o \
ft_putendl_fd.o \
ft_putnbr_fd.o \
ft_split.o

BONUS = ft_lstnew_bonus.o \
ft_lstadd_front_bonus.o \
ft_lstsize_bonus.o \
ft_lstlast_bonus.o \
ft_lstadd_back_bonus.o \
ft_lstdelone_bonus.o \
ft_lstclear_bonus.o \
ft_lstiter_bonus.o \
ft_lstmap_bonus.o

EXTRA = extra/ft_sign.o \
extra/ft_itoa_base.o \
extra/ft_nbr_abs_len.o \
extra/ft_nbr_len.o \
extra/ft_nbr_len_unsigned.o \
extra/ft_putnbr_base_fd.o \
extra/ft_itoa_base_unsigned.o \
extra/ft_putnbr_base_unsigned_fd.o

all: $(NAME)

$(NAME): $(SRC)
	ar rc $@ $?
	ranlib $@

.c.o:
	$(CC) $(CFLAGS) -c $? -o $@


clean:
	rm -rf $(SRC) $(BONUS) $(EXTRA)

fclean:	clean
	rm -f $(NAME)

re: fclean all

bonus: $(SRC) $(BONUS)
	ar rcs $(NAME) $(SRC) $(BONUS)

extra: $(SRC) $(BONUS) $(EXTRA)
	ar rcs $(NAME) $(SRC) $(BONUS) $(EXTRA)

