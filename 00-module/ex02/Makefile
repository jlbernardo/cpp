# -*- Makefile -*-

NAME	=	account

CC		=	c++
FLAGS	=	-Werror -Wall -Wextra -g3 -std=c++98

INCLUDE	=	-I.

OD		=	obj/

SRC		=	tests.cpp Account.cpp
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
	@./$(NAME) > compare.log
	@vimdiff 19920104_091532.log compare.log
	@rm -rf $(OD)
	@rm -f $(NAME)
	@rm -f compare.log

clean:
	@rm -rf $(OD)
	@echo "$(BLU) All objects were deleted.$(DFL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLU) Binary file deleted.$(DFL)"

re: fclean all

.PHONY: all clean fclean re
