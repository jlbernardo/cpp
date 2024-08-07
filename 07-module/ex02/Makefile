# -*- Makefile -*-

NAME	=	array

CC		=	c++
FLAGS	=	-Werror -Wall -Wextra -Wshadow -g3 -std=c++98

INCLUDE	+=	-I ../includes/
INCLUDE	+=	-I .
INCLUDE	+=	-I ./Cat/
INCLUDE	+=	-I ./Fixed/
INCLUDE	+=	-I ./Animal/

OD		=	obj/

SRC		+=	main.cpp Fixed/Fixed.cpp Cat/Cat.cpp Animal/Animal.cpp
OBJ		=	$(SRC:%.cpp=$(OD)%.o)

BLU 	=	\033[1;36m
DFL 	=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLU) Compiling...$(DFL)"
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJ) -o $@
	@echo "$(BLU) All done!$(DFL)"

$(OD)%.o:%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

run: all
	@clear
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME)
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
