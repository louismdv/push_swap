# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:17:41 by louismdv          #+#    #+#              #
#    Updated: 2024/02/05 17:08:40 by lmerveil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap.a
EXECUTABLE	= 	push_swap

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
				calculations			\
				ft_sort3				\
				operations				\
				sortings				\
				utils					\
				)						\
				))						\

OFILES		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "$(GREEN)[$(CC)]$(NC) compilation: $(YELLOW)$<$(NC)\r\c"


all: 	$(EXECUTABLE)

${LIBFT_LIB}:
	@make -C $(LIBFT_PATH) -s
	@cp $(LIBFT_LIB) ./$(NAME)
	@echo "$(GREEN)[LIBFT Library]$(NC) copying to: $(YELLOW)$(NAME)$(NC)"

$(EXECUTABLE): $(LIBFT_LIB) $(OFILES)
	@$(CC) $(CFLAGS) $^ -o $@ -L./libft -lft
	@echo "$(GREEN)[Executable]$(NC) created successfully: $(YELLOW)$(EXECUTABLE)$(NC)"

$(NAME): ${LIBFT_LIB} $(OFILES)
	@ar rcs $(NAME) $(OFILES) -s
	@echo "$(GREEN)[PUSH_SWAP Library]$(NC) created successfully: $(YELLOW)$(NAME)$(NC)"

clean:
	@make clean -C $(LIBFT_PATH) -s
	@rm -f $(OFILES)
	@echo "$(RED)[clean]$(NC) deleting OFILES: $(YELLOW)$(OFILES)$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) -s
	@rm -f $(EXECUTABLE)
	@echo "$(RED)[fclean]$(NC) deleting library: $(YELLOW)$(NAME)$(NC)"

re: fclean all
	@echo "$(GREEN)[re]$(NC) rebuilding project: $(YELLOW)$(NAME)$(NC)"

.PHONY: all clean fclean re

