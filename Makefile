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
CFLAGS = -Wall -Wextra -Werror

OTHER_FUNCS =  ft_bzero \
ft_strlen \
ft_strlcat \
ft_strlcpy \
ft_strchr \
ft_strrchr \
ft_strncmp \
ft_strnstr \
ft_atoi \
ft_calloc \
ft_strdup \
ft_substr \
ft_strjoin \
ft_strtrim \
ft_itoa \
ft_strmapi \
ft_striteri \
ft_putchar_fd \
ft_putstr_fd \
ft_putendl_fd \
ft_putnbr_fd \
ft_split

EXTRA_FUNCS = ft_sign \
ft_itoa_base \
ft_nbr_abs_len \
ft_nbr_len \
ft_nbr_len_unsigned \
ft_putnbr_base_fd \
ft_itoa_base_unsigned \
ft_putnbr_base_unsigned_fd \
ft_split2

LIST_FUNCS = ft_lstadd_back \
ft_lstadd_front \
ft_lstclear \
ft_lstdelone \
ft_lstiter \
ft_lstlast \
ft_lstmap \
ft_lstnew \
ft_lstsize

CTYPE_FUNCS = ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_tolower \
ft_toupper

MEM_FUNCS = ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memmove \
ft_memset

INCLUDE_PATH := -I.

LIST_OBJS = $(addsuffix .o, $(addprefix linked-lists/, $(LIST_FUNCS)))

ALL_OBJS := $(addsuffix .o, $(addprefix mem/, $(MEM_FUNCS)) $(addprefix ctype/, $(CTYPE_FUNCS)) $(addprefix extra/, $(EXTRA_FUNCS)) $(OTHER_FUNCS))

ifndef NOLIST
	ALL_OBJS += $(LIST_OBJS)
	INCLUDE_PATH += -Ilinked-lists
endif

all: $(NAME)

$(NAME): $(ALL_OBJS)
	ar rc $@ $?
	ranlib $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $? -o $@


clean:
	rm -rf $(ALL_OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

