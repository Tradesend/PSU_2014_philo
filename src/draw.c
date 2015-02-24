/*
** draw.c for philo in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Feb 23 11:40:07 2015 Julie Terranova
** Last update Tue Feb 24 15:42:43 2015 moran-_d
*/

#include <pthread.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"
#include "X11/Xlib.h"
#include "philosophe.h"

SDL_Surface *load_image(char *filename)
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;

  loadedImage = SDL_LoadBMP(filename);
  if (loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormat(loadedImage);
      SDL_FreeSurface(loadedImage);
    }
  return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
  SDL_Rect offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(source, NULL, destination, &offset);
}

int	draw(int nb)
{
  SDL_Surface *table = NULL;
  SDL_Surface *background = NULL;
  SDL_Surface *screen = NULL;

  XInitThreads();
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (-1);
  if ((screen = SDL_SetVideoMode(900, 600, 32, SDL_SWSURFACE)) == NULL)
    return (-1);
  SDL_WM_SetCaption("Graphic version - Philosophers", NULL);
  //Chargement des images:
  if ((table = load_image("pictures/table.bmp")) == NULL)
    return (-1);
  if ((background = load_image("pictures/background.bmp")) == NULL)
    return (-1);
  //On applique le fond sur l'écran:
  apply_surface(0, 0, background, screen);
  apply_surface(180, 140, table, screen);

  if (SDL_Flip(screen) == -1)
    return (-1);

  build(nb);

  //Libération des surfaces
  SDL_FreeSurface(table);
  SDL_FreeSurface(background);

  SDL_Quit();
  return (0);
}
