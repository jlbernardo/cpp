# -*- Makefile -*-

NAME	=	materia

CC		=	c++
FLAGS	=	-Werror -Wall -Wextra -Wshadow -g3 -std=c++98

INCLUDE	+=	-I ../includes/
INCLUDE +=	$(addprefix -I ./classes/, Materia/ Character/ MateriaSource/ \
						Ice/ Cure/ Fire/ Thunder/ Dark/ Game/)

OD		=	obj/

SRC		+=	main.cpp
SRC		+=	$(addprefix classes/, Materia/AMateria.cpp Character/Character.cpp \
						MateriaSource/MateriaSource.cpp Ice/Ice.cpp Cure/Cure.cpp \
						Fire/Fire.cpp Thunder/Thunder.cpp Dark/Dark.cpp \
						Game/Game.cpp Game/Game.battle.cpp Game/Game.characters.cpp \
						Game/Game.finish.cpp Game/Game.introduction.cpp \
						Game/Game.messages.cpp Game/Game.setup.cpp)
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
