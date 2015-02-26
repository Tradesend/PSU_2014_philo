/*
** main.c for main in /home/moran-_d/rendu/PSU_2014_philo
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Thu Feb 26 13:05:58 2015 moran-_d
** Last update Thu Feb 26 13:06:48 2015 moran-_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philosophe.h"

int main(int argc, char **argv)
{
  int nb;

  if (argc < 2)
    nb = 7;
  else if ((nb = atoi(argv[1])) < 3)
    {
      printf("Need at least 3 philosophers\n");
      return (-1);
    }
  else if (nb > 50)
    {
      printf("Nice try\n");
      return (-1);
    }
  if (draw(nb) == -1)
    return (printf("Something went wrong with the SDL\n"));
  return (0);
}
