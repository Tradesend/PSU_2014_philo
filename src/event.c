/*
** event.c for event in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Tue Feb 24 19:26:36 2015 Julie Terranova
** Last update Wed Feb 25 13:28:25 2015 Julie Terranova
*/

#include <pthread.h>
#include <unistd.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"
#include "philosophe.h"

int	move_picture(char *id, char *action, t_sdl *my_struct)
{
  //sleep(0.5); // pr image mais pas pr affichage?

  apply_surface(20, 20, my_struct->stick, my_struct->screen);
  printf("\nmove_picture() is called\n");
  action = action;
  id = id;

  return (0);
}
