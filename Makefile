# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 10:31:58 by skoulen           #+#    #+#              #
#    Updated: 2023/03/01 16:42:44 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#some escape sequences
MOVE_UP = "\033[1A"
ERASE_END = "\033[K"

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

MANDATORY_FUNCS = \
ft_bzero \
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
ft_split \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_tolower \
ft_toupper \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memmove \
ft_memset \

LIST_FUNCS = ft_lstadd_back \
ft_lstadd_front \
ft_lstclear \
ft_lstdelone \
ft_lstiter \
ft_lstlast \
ft_lstmap \
ft_lstnew \
ft_lstsize

EXTRA_FUNCS = \
ft_sign \
ft_isspace \
ft_itoa_base \
ft_nbr_abs_len \
ft_nbr_len \
ft_nbr_len_unsigned \
ft_putnbr_base_fd \
ft_itoa_base_unsigned \
ft_putnbr_base_unsigned_fd \
ft_split2 \
ft_strcmp

HEADERS := ./includes

FILES := $(MANDATORY_FUNCS)
ifndef FT_NO_LIST
	FILES += $(LIST_FUNCS)
endif
ifndef FT_NO_EXTRA
	FILES += $(EXTRA_FUNCS)
endif

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(addprefix objs/, $(FILES)))

INCLUDE_PATH = $(addprefix -I, $(HEADERS))

all: format $(NAME)

format:
	@echo libft up-to-date

$(NAME): $(OBJS) $(HEADERS)
	@echo $(MOVE_UP)archiving the lib$(ERASE_END)
	@ar rcs $@ $(OBJS)
	@echo $(MOVE_UP)libft ok$(ERASE_END)

objs/%.o: %.c
	@mkdir -p objs
	@echo $(MOVE_UP)compiling $< $(ERASE_END)
	@$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@


clean: format
	@echo $(MOVE_UP)removing object files$(ERASE_END)
	@rm -rf objs

fclean:	clean
	@echo $(MOVE_UP)removing the lib$(ERASE_END)
	@rm -f $(NAME)

re: format fclean $(NAME)

.PHONY: clean fclean all re format
