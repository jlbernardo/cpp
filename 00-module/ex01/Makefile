# -*- Makefile -*-

NAME	= phonebook

CC		= c++
FLAGS	= -Werror -Wall -Wextra -g3 -std=c++98

INCLUDE	= -I ./includes/

OD		= obj/

SRC		+=	$(addprefix main/, catalog.cpp catalog_utils.cpp)
SRC		+=	$(addprefix ClassPhoneBook/, PhoneBookMethods.cpp PhoneBookUtils.cpp)
SRC		+=	$(addprefix ClassContact/, ContactGetters.cpp ContactSetters.cpp ContactMethods.cpp ContactUtils.cpp)
OBJ		= $(SRC:%.cpp=$(OD)%.o)

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
	@./$(NAME)
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
