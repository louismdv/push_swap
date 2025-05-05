# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:17:41 by louismdv          #+#    #+#              #
#    Updated: 2024/02/08 15:35:40 by lmerveil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap

CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror -I./include -g3

RED			= 	$(shell tput setaf 1)
GREEN		= 	$(shell tput setaf 2)
YELLOW		= 	$(shell tput setaf 3)
NC			= 	$(shell tput sgr0)

LIBFT_PATH	=	./libft
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

SRCS		 = 	$(addsuffix .c,			\
				main					\
				$(addprefix srcs/, 		\
				$(addprefix parsing_,	\
				check_input				\
				ft_parse_int			\
				ft_parse				\
				ft_parse_quoted			\
				init_lst				\
				)						\
				$(addprefix stacking_,	\
				atob					\
				btoa					\
				target_node				\
				ft_sort3				\
				operations1				\
				operations2				\
				sortings				\
				utils					\
				)						\
				calculations_push_cost	\
				))						\

OFILES		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "$(GREEN)[$(CC)]$(NC) compilation: $(YELLOW)$<$(NC)\r\c"


all: 	$(NAME)

${LIBFT_LIB}:
	@make -C $(LIBFT_PATH) -s
	@cp $(LIBFT_LIB) ./$(NAME)
	@echo "$(GREEN)[LIBFT Library]$(NC) copying to: $(YELLOW)$(NAME)$(NC)"

$(NAME): $(LIBFT_LIB) $(OFILES)
	@$(CC) $(CFLAGS) $^ -o $@ -L./libft -lft
	@echo "$(GREEN)[Executable]$(NC) created successfully: $(YELLOW)$(NAME)$(NC)"

clean:
	@make clean -C $(LIBFT_PATH) -s
	@rm -f $(OFILES)
	@echo "$(RED)[clean]$(NC) deleting OFILES: $(YELLOW)$(OFILES)$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) -s
	@rm -f $(NAME)
	@echo "$(RED)[fclean]$(NC) deleting library: $(YELLOW)$(NAME)$(NC)"

re: fclean all
	@echo "$(GREEN)[re]$(NC) rebuilding project: $(YELLOW)$(NAME)$(NC)"

.PHONY: all clean fclean re

