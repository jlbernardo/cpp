# -*- Makefile -*-

NAME	=	RPN

CC		=	c++
FLAGS	=	-Werror -Wall -Wextra -Wshadow -g3 -std=c++98

INCLUDE	+=	-I ../includes/
INCLUDE	+=	-I .

OD		=	obj/

SRC		+=	main.cpp RPN.cpp
OBJ		=	$(SRC:%.cpp=$(OD)%.o)

BLU 	=	\033[1;36m
DFL 	=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLU) Compiling...$(DFL)"
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJ) -o $@
	@echo "$(BLU) All done!$(DFL)"

$(OD)%.o:%.cpp
	@mkdir -p $(dir $@)typename
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

run: all
	@clear
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) "7 7 * 7 -"
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) "(1 + 1)"
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME)
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) "8 6 4 + - *"
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) "8 0 /"
	@rm -rf $(OD)
	@rm -f $(NAME)

clean:
	@rm -rf $(OD)
	@echo "$(BLU) All objects were deleted.$(DFL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLU) Binary file deleted.$(DFL)"

re: fclean all

.PHONY: all clean fclean re
