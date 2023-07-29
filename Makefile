# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 15:43:43 by sbalk             #+#    #+#              #
#    Updated: 2023/07/29 15:57:18 by sbalk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm
SRC_DIR		= src/
OBJ_DIR		= obj/
DOBJ_DIR	= dobj/
AR			= ar rcs
INCLUDE		= -I include

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

SRC_FILES	=	error_handling \
				list_utils \
				push \
				reverse_rotate \
				rotate \
				swap \
				utils \
				quicksort \
				small_sorting \
				quicksort_stack \
				insertion_sort \
				push_swap \
				create_stack \
				string_func \
				array_list_func
				

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ	 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DOBJ	 	= 	$(addprefix $(DOBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "$(GREEN)Created $(NAME)!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(DOBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(DOBJ_DIR)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -g

bonus:		$(NAME)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf $(DOBJ_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)push_swap!$(DEF_COLOR)"

norm:
			@norminette $(SRC) include/$(NAME).h| grep -v Norme -B1 || true

debug:		$(DOBJ)
			@$(CC) $(CFLAGS) $(DOBJ) -o $(NAME) -g
			@echo "$(GREEN)Created $(NAME) DEBUG BUILD!$(DEF_COLOR)"

debugre:	fclean debug
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME) DEBUG BUILD!$(DEF_COLOR)"

git:		fclean
			@git status
			@git add *
			@git status

.PHONY:		all clean fclean re norm debug debugre git