##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
RED_C	=	"\e[31m"
L_RED	=	"\e[91m"
BLUE_C	=	"\e[34m"
L_BLUE	=	"\e[94m"
GREEN_C	=	"\e[32m"
L_GREEN	=	"\e[92m"

C_T	=	$(BLUE_C)
T_T	=	$(RED_C)

CC	=	gcc

SRC	=	$(shell find ./ -name '*.c')

TEMP_FILE	=	$(shell find ./ -name '*~')

CFLAG	=	-Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

NAME	=	morpion

all: $(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAG) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(L_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(BLUE_C)"BUILD FAILED:" $(L_RED) "$(NAME)\n"$(DEFAULT)
	@cp $(NAME) ../

%.o:	%.c
	$(CC) -o $@ -c $< -g3 $(CFLAG)

clean:
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@$(ECHO) $(RED_C)$(BOLD_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(L_RED)"$(NAME)'s object files"$(DEFAULT)
	@rm -f vgcore.*
	@rm -f $(TEMP_FILE)
	@$(ECHO) $(RED_C)$(BOLD_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(L_RED)"Valgrind and temporals files"$(DEFAULT)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@$(ECHO) $(RED_C)$(BOLD_T)"[fclean] "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(L_RED)"Binary $(NAME)"$(DEFAULT)

re:	fclean all