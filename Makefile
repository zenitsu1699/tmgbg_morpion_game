##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## MAKEFILE
##

all:
	make -C project

clean:
	make clean -C project

fclean:
	make fclean -C project

re: fclean all