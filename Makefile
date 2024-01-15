# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:17:41 by louismdv          #+#    #+#              #
#    Updated: 2024/01/13 23:14:53 by louismdv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap.a

CC 			= 	gcc
CFLAGS 		= 	-Wall -Wextra -Werror -g

RED			= 	$(shell tput setaf 1)
GREEN		= 	$(shell tput setaf 2)
YELLOW		= 	$(shell tput setaf 3)
NC			= 	$(shell tput sgr0)

LIBFT_PATH	=	./libft
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

SRCS		 = 	$(addsuffix .c,		\
				$(addprefix srcs/, 	\
				parsing 			\
				))

OFILES		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -I include -c $< -o $@
	@echo "$(GREEN)[$(CC)]$(NC) compilation: $(YELLOW)$<$(NC)\r\c"

all: 	$(NAME)

${LIBFT_LIB}:
	@make -C $(LIBFT_PATH) 
	@cp $(LIBFT_LIB) ./$(NAME)
	@echo "$(GREEN)[LIBFT Library]$(NC) copying to: $(YELLOW)$(NAME)$(NC)"

$(NAME): ${LIBFT_LIB} $(OFILES)
	@ar rcs $(NAME) $(OFILES) -o $(NAME)
	@echo "$(GREEN)[PUSH_SWAP Library]$(NC) created successfully: $(YELLOW)$(NAME)$(NC)"

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OFILES)
	@echo "$(RED)[clean]$(NC) deleting OFILES: $(YELLOW)$(OFILES)$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)[fclean]$(NC) deleting library: $(YELLOW)$(NAME)$(NC)"

re: fclean all
	@echo "$(GREEN)[re]$(NC) rebuilding project: $(YELLOW)$(NAME)$(NC)"

.PHONY: all clean fclean re

