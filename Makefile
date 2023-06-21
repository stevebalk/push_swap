# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 15:43:43 by sbalk             #+#    #+#              #
#    Updated: 2023/06/21 14:01:14 by sbalk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
SRC_DIR		= src/
OBJ_DIR		= obj/
AR			= ar rcs
INCLUDE		= include

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	push_swap \
				error_handling \
				list_utils \
				push \
				reverse_rotate \
				rotate \
				swap \
				utils

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

bonus:		$(NAME)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(SRCB) $(INCLUDE) | grep -v Norme -B1 || true

debug:		

.PHONY:		all clean fclean re norm debug