# -*- Makefile -*-

NAME	=	PmergeMe

CC		=	c++
FLAGS	=	-Werror -Wall -Wextra -Wshadow -g3 -std=c++98

INCLUDE	+=	-I ../includes/
INCLUDE	+=	-I .

OD		=	obj/

SRC		+=	main.cpp PmergeMe.canonical.cpp \
					PmergeMe.validation.cpp \
					PmergeMe.vector.cpp \
					PmergeMe.deque.cpp
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
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) 2 4 3 6 1 0 5 9 7 8
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) 1 2 3 4 5 6 7 8 9
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) 3 5 -9 7 4
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) 3 5 5 7 4
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) 3 5 b 7 4
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME)
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME) `shuf -i 1-3000 -n 3000 | tr "\n" " " `
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
