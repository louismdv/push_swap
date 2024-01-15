# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 11:33:24 by louismdv          #+#    #+#              #
#    Updated: 2024/01/13 23:13:51 by louismdv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC = cc
CFLAGS	=	-Wall -Wextra -Werror -I.

SOURCES = ft_atoi.c\
		 ft_strrchr.c\
		 ft_bzero.c\
		 ft_calloc.c\
		 ft_isalnum.c\
		 ft_isalpha.c\
		 ft_isascii.c\
		 ft_isdigit.c\
		 ft_isprint.c\
		 ft_memchr.c\
		 ft_memcmp.c\
		 ft_memcpy.c\
		 ft_memmove.c\
		 ft_memset.c\
		 ft_strchr.c\
		 ft_strdup.c\
		 ft_strlcat.c\
		 ft_strlcpy.c\
		 ft_strlen.c\
		 ft_strncmp.c\
		 ft_strnstr.c\
		 ft_tolower.c\
		 ft_toupper.c\
		 ft_striteri.c\
		 ft_putnbr_fd.c\
		 ft_putendl_fd.c\
		 ft_putstr_fd.c\
		 ft_putchar_fd.c\
		 ft_strmapi.c\
		 ft_split.c\
		 ft_itoa.c\
		 ft_substr.c\
		 ft_strtrim.c\
		 ft_strjoin.c\

OBJ = $(SOURCES:.c=.o)

BONUS = ft_lstnew.c\
		ft_lstsize.c\
		ft_lstadd_front.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstiter.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstmap.c\

BOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(BOBJ)
	@ar rcs $(NAME) $(OBJ) $(BOBJ)

clean:
	@rm -f $(OBJ) $(BOBJ)

fclean:
	@rm -f $(OBJ) $(NAME) $(BOBJ)

re: clean all

.PHONY: all clean flcean re bonus
