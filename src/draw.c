/*
** draw.c for philo in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Feb 23 11:40:07 2015 Julie Terranova
** Last update Thu Feb 26 19:41:33 2015 Julie Terranova
*/

#include <pthread.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"
#include "X11/Xlib.h"
#include "philosophe.h"

SDL_Surface	*optimize_img(char *file)
{
  SDL_Surface	*first_one;
  SDL_Surface	*opti_one;

  first_one = NULL;
  opti_one = NULL;
  first_one = SDL_LoadBMP(file);
  if (first_one != NULL)
    {
      opti_one = SDL_DisplayFormat(first_one);
      SDL_FreeSurface(first_one);
    }
  return (opti_one);
}

void	apply_surface(int x, int y, SDL_Surface* src, SDL_Surface* dest)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, dest, &offset);
}

void	init(t_sdl *mine)
{
  mine->stick = NULL;
  mine->background = NULL;
  mine->screen = NULL;
}

int	draw(int nb)
{
  t_sdl	mine;

  init(&mine);
  XInitThreads();
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (-1);
  if ((mine.screen = SDL_SetVideoMode(900, 600, 32, SDL_SWSURFACE)) == NULL)
    return (-1);
  SDL_WM_SetCaption("Graphic version - Philosophers", NULL);
  if ((mine.stick = optimize_img("pictures/stick.bmp")) == NULL)
    return (-1);
  if ((mine.background = optimize_img("pictures/background.bmp")) == NULL)
    return (-1);
  if (SDL_Flip(mine.screen) == -1)
    return (-1);
  build(nb, &mine);
  SDL_FreeSurface(mine.stick);
  SDL_FreeSurface(mine.background);
  SDL_Quit();
  return (0);
}
