##
## Makefile for Makefile in /home/moran-_d/rendu/PSU_2014_philo
##
## Made by moran-_d
## Login   <moran-_d@epitech.net>
##
## Started on  Tue Feb 17 08:58:30 2015 moran-_d
## Last update Thu Feb 26 19:09:53 2015 Julie Terranova
##

NAME=   philo

DIR=    src/

SRC=	$(DIR)main.c \
	$(DIR)manage_static.c \
	$(DIR)action.c \
        $(DIR)philosophe.c \
	$(DIR)draw.c \
	$(DIR)event.c \

OBJ=    $(SRC:.c=.o)

CFLAGS= -Wall -Wextra -Werror -I include/

LDFLAGS= -lpthread -lSDLmain -lSDL -lX11 -lSDL_ttf

all:    $(NAME)

$(NAME):$(OBJ)
	cc -o $(NAME) $(LDFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
