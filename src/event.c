/*
** event.c for event in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Tue Feb 24 19:26:36 2015 Julie Terranova
** Last update Thu Feb 26 13:02:57 2015 moran-_d
*/

#include <pthread.h>
#include <unistd.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_thread.h"
#include "philosophe.h"

/* 0 = sleep ; 1 = eat ; 2 = think right ; 3 = think left */
void create_event(int action2, int id2)
{
  SDL_Event user_event;
  int *action;
  int *id;

  if ((action = malloc(sizeof(*action))) == NULL)
    return;
  if ((id = malloc(sizeof(*id))) == NULL)
    return;
  action[0] = action2;
  id[0] = id2;
  user_event.type = SDL_USEREVENT;
  user_event.user.code = action2;
  user_event.user.data1 = id;
  user_event.user.data2 = action;
  SDL_PushEvent(&user_event);
}

int	move_picture(int *id, int *action, t_sdl *my_struct)
{
  SDL_Surface *message;
  TTF_Font *font;
  SDL_Color textColor;
  char *str;

  str = malloc(sizeof(*str) * 100);
  font = NULL;
  message = NULL;
  textColor.r = 255;
  textColor.b = 255;
  textColor.g = 255;

  if (TTF_Init() == -1)
    return (-1);

  font = TTF_OpenFont("pictures/police.ttf", 28);

  if (font == NULL) // font toujours == NULL
    return (-1);

  //sleep(0.5); // pr image mais pas pr affichage?
  if (SDL_Flip(my_struct->screen) == -1)
    return (-1);

  if (action[0] == 0) // sleeps
    {
      apply_surface(0, 0, my_struct->background, my_struct->screen);
      apply_surface(200, 425, my_struct->stick, my_struct->screen);
      apply_surface(710, 425, my_struct->stick, my_struct->screen);
      printf("The philosopher n %d is sleeping\n", id[0]);
      sprintf(str, "The philosopher n %d                                    is sleeping", id[0]);
      if ((message = TTF_RenderText_Solid( font, str, textColor )) == NULL)
	return (-1);
      apply_surface( 50, 180, message, my_struct->screen );
    }
  else if (action[0] == 1) // eats
    {
      apply_surface(0, 0, my_struct->background, my_struct->screen);
      apply_surface(440, 400, my_struct->stick, my_struct->screen);
      apply_surface(460, 400, my_struct->stick, my_struct->screen);
      printf("The philosopher n %d is eating\n", id[0]);
      sprintf(str, "The philosopher n %d                                    is eating", id[0]);
      message = TTF_RenderText_Solid( font, str, textColor );
      if (message == NULL)
	return (-1);
      apply_surface( 50, 180, message, my_struct->screen );
    }
  else // dedans exec une autre func (norme)
    {
      if (action[0] == 2) // thinks right
	{
	  apply_surface(0, 0, my_struct->background, my_struct->screen);
	  apply_surface(200, 200, my_struct->stick, my_struct->screen);
	  apply_surface(710, 425, my_struct->stick, my_struct->screen);
	  printf("The philosopher n %d is thinking right\n", id[0]);
	  sprintf(str, "The philosopher n %d                                    is thinking right", id[0]);
	  message = TTF_RenderText_Solid( font, str, textColor );
	  if (message == NULL)
	    return (-1);
	  apply_surface( 50, 180, message, my_struct->screen );
	}
      else if (action[0] == 3) // thinks left
	{
	  apply_surface(0, 0, my_struct->background, my_struct->screen);
	  apply_surface(200, 425, my_struct->stick, my_struct->screen);
	  apply_surface(710, 200, my_struct->stick, my_struct->screen);
	  printf("The philosopher n %d is thinking left\n", id[0]);
	  sprintf(str, "The philosopher n %d                                    is thinking left", id[0]);
	  message = TTF_RenderText_Solid( font, str, textColor );
	  if (message == NULL)
	    return (-1);
	  apply_surface( 50, 180, message, my_struct->screen );
	}
    }
  //clear surfaces ici! (si possible)

  free(str);
  TTF_CloseFont( font );
  TTF_Quit();
  return (0);
}
