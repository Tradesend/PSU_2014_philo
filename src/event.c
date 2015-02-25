/*
** event.c for event in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Tue Feb 24 19:26:36 2015 Julie Terranova
** Last update Wed Feb 25 20:39:33 2015 Julie Terranova
*/

#include <pthread.h>
#include <unistd.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"
#include "philosophe.h"

int	move_picture(int *id, int *action, t_sdl *my_struct)
{
  id = id;
  action = action;
  //sleep(0.5); // pr image mais pas pr affichage?
  if (SDL_Flip(my_struct->screen) == -1)
    return (-1);
  printf("coucou\n");

  if (action[0] == 0) // sleeps
    {
      apply_surface(0, 0, my_struct->background, my_struct->screen);
      apply_surface(200, 425, my_struct->stick, my_struct->screen);
      apply_surface(710, 425, my_struct->stick, my_struct->screen);
    }
  else if (action[0] == 1) // eats
    {
      apply_surface(0, 0, my_struct->background, my_struct->screen);
      apply_surface(440, 400, my_struct->stick, my_struct->screen);
      apply_surface(460, 400, my_struct->stick, my_struct->screen);
    }
  else // dedans exec une autre func (norme)
    {
      if (action[0] == 2) // thinks right
	{
	  apply_surface(0, 0, my_struct->background, my_struct->screen);
	  apply_surface(200, 200, my_struct->stick, my_struct->screen);
	  apply_surface(710, 425, my_struct->stick, my_struct->screen);
	}
      else if (action[0] == 3) // thinks left
	{
	  apply_surface(0, 0, my_struct->background, my_struct->screen);
	  apply_surface(200, 425, my_struct->stick, my_struct->screen);
	  apply_surface(710, 200, my_struct->stick, my_struct->screen);
	}
    }

  return (0);
}
