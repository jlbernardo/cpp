# -*- Makefile -*-

NAME	=	intern

CC		=	c++
FLAGS	=	-Werror -Wall -Wextra -Wshadow -g3 -std=c++98

INCLUDE	+=	-I .
INCLUDE	+=	-I ../includes/
INCLUDE += $(addprefix -I ./classes/, Bureaucrat/ Form/ Pardon/ Shrubbery/ \
							Robotomy/ Intern/)

OD		=	obj/

SRC		+=	main.cpp office.cpp
SRC		+=	$(addprefix classes/, Bureaucrat/Bureaucrat.cpp Form/AForm.cpp \
				Pardon/PresidentialPardonForm.cpp Robotomy/RobotomyRequestForm.cpp \
				Shrubbery/ShrubberyCreationForm.cpp Intern/Intern.cpp)
OBJ		=	$(SRC:%.cpp=$(OD)%.o)

BLU 	=	\033[1;36m
GRN 	=	\033[1;32m
YLW 	=	\033[1;33m
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
	@echo "$(YLW)             🪄  APPARITION!! 🪄\n\n $(GRN)"
	@cat *_shrubbery
	@echo "\n $(YLW)      😊 Yup, it is really there! 👏 \n $(DFL)"
	@rm -rf $(OD)
	@rm -f $(NAME)
	@rm -f *_shrubbery

clean:
	@rm -rf $(OD)
	@rm -f *_shrubbery
	@echo "$(BLU) All objects were deleted.$(DFL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLU) Binary file deleted.$(DFL)"

re: fclean all

.PHONY: all clean fclean re
