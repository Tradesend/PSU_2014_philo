/*
** event_sleep.c for sleep in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Thu Feb 26 20:26:01 2015 Julie Terranova
** Last update Thu Feb 26 20:46:08 2015 Julie Terranova
*/

#include <pthread.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_thread.h"
#include "philosophe.h"

void	sleeps(t_sdl *mine, int *id, t_ttf sent)
{
  apply_surface(0, 0, mine->background, mine->screen);
  apply_surface(200, 425, mine->stick, mine->screen);
  apply_surface(710, 425, mine->stick, mine->screen);
  printf("The philosopher n %d is sleeping\n", id[0]);
  sprintf(sent.str, "The philosopher n %d is sleeping", id[0]);
  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
      == NULL)
    return;
  apply_surface(250, 50, sent.msg, mine->screen);
}

void	eats(t_sdl *mine, int *id, t_ttf sent)
{
  apply_surface(0, 0, mine->background, mine->screen);
  apply_surface(440, 400, mine->stick, mine->screen);
  apply_surface(460, 400, mine->stick, mine->screen);
  printf("The philosopher n %d is eating\n", id[0]);
  sprintf(sent.str, "The philosopher n %d is eating", id[0]);
  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
      == NULL)
    return;
  apply_surface(250, 50, sent.msg, mine->screen);
}

void	thinksright(t_sdl *mine, int *id, t_ttf sent)
{
  apply_surface(0, 0, mine->background, mine->screen);
  apply_surface(200, 200, mine->stick, mine->screen);
  apply_surface(710, 425, mine->stick, mine->screen);
  printf("The philosopher n %d is thinking right\n", id[0]);
  sprintf(sent.str, "The philosopher n %d is thinking right", id[0]);
  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
      == NULL)
    return;
  apply_surface(250, 50, sent.msg, mine->screen);
}

void	thinksleft(t_sdl *mine, int *id, t_ttf sent)
{
  apply_surface(0, 0, mine->background, mine->screen);
  apply_surface(200, 425, mine->stick, mine->screen);
  apply_surface(710, 200, mine->stick, mine->screen);
  printf("The philosopher n %d is thinking left\n", id[0]);
  sprintf(sent.str, "The philosopher n %d is thinking left", id[0]);
  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
      == NULL)
    return;
  apply_surface(250, 50, sent.msg, mine->screen);
}
