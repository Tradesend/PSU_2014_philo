/*
** event.c for event in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Tue Feb 24 19:26:36 2015 Julie Terranova
** Last update Thu Feb 26 20:18:49 2015 Julie Terranova
*/

#include <pthread.h>
#include <unistd.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_thread.h"
#include "philosophe.h"

void	create_event(int action2, int id2)
{
  SDL_Event	user_event;
  int		*action;
  int		*id;

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

void	init_picture(t_ttf *sent)
{
  sent->font = NULL;
  sent->msg = NULL;
  sent->txtColor.r = 255;
  sent->txtColor.b = 255;
  sent->txtColor.g = 255;
}

int	move_picture(int *id, int *action, t_sdl *mine)
{
  t_ttf sent;

  init_picture(&sent);
  if ((sent.str = malloc(sizeof(*sent.str) * 100)) == NULL)
    return (-1);
  if (TTF_Init() == -1)
    return (-1);
  if ((sent.font = TTF_OpenFont("pictures/police.ttf", 28)) == NULL)
    return (-1);
  if (SDL_Flip(mine->screen) == -1)
    return (-1);

  if (action[0] == 0)
    {
      apply_surface(0, 0, mine->background, mine->screen);
      apply_surface(200, 425, mine->stick, mine->screen);
      apply_surface(710, 425, mine->stick, mine->screen);
      printf("The philosopher n %d is sleeping\n", id[0]);
      sprintf(sent.str, "The philosopher n %d is sleeping", id[0]);
      if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor)) == NULL)
	return (-1);
      apply_surface(250, 50, sent.msg, mine->screen);
    }
  else if (action[0] == 1)
    {
      apply_surface(0, 0, mine->background, mine->screen);
      apply_surface(440, 400, mine->stick, mine->screen);
      apply_surface(460, 400, mine->stick, mine->screen);
      printf("The philosopher n %d is eating\n", id[0]);
      sprintf(sent.str, "The philosopher n %d is eating", id[0]);
      if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor)) == NULL)
	return (-1);
      apply_surface(250, 50, sent.msg, mine->screen);
    }
  else // dedans exec une autre func (norme)
    {
      if (action[0] == 2)
	{
	  apply_surface(0, 0, mine->background, mine->screen);
	  apply_surface(200, 200, mine->stick, mine->screen);
	  apply_surface(710, 425, mine->stick, mine->screen);
	  printf("The philosopher n %d is thinking right\n", id[0]);
	  sprintf(sent.str, "The philosopher n %d is thinking right", id[0]);
	  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor)) == NULL)
	    return (-1);
	  apply_surface(250, 50, sent.msg, mine->screen);
	}
      else if (action[0] == 3)
	{
	  apply_surface(0, 0, mine->background, mine->screen);
	  apply_surface(200, 425, mine->stick, mine->screen);
	  apply_surface(710, 200, mine->stick, mine->screen);
	  printf("The philosopher n %d is thinking left\n", id[0]);
	  sprintf(sent.str, "The philosopher n %d is thinking left", id[0]);
	  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor)) == NULL)
	    return (-1);
	  apply_surface(250, 50, sent.msg, mine->screen);
	}
    }

  free(sent.str);
  TTF_CloseFont(sent.font);
  TTF_Quit();
  return (0);
}
