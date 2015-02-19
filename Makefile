##
## Makefile for Makefile in /home/moran-_d/rendu/PSU_2014_philo
##
## Made by moran-_d
## Login   <moran-_d@epitech.net>
##
## Started on  Tue Feb 17 08:58:30 2015 moran-_d
## Last update Tue Feb 17 09:21:39 2015 moran-_d
##

NAME=   philo

DIR=    src/

SRC=	$(DIR)action.c \
        $(DIR)philosophe.c

OBJ=    $(SRC:.c=.o)

CFLAGS= -Wall -Wextra -I include/ -g 

LDFLAGS= -lpthread

all:    $(NAME)

$(NAME):        $(OBJ)
	cc -o $(NAME) $(LDFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:         clean
	rm -f $(NAME)

re:     fclean all
