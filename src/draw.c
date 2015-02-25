/*
** draw.c for philo in /home/terran_j/rendu/PSU_2014_philo/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Feb 23 11:40:07 2015 Julie Terranova
** Last update Wed Feb 25 20:38:27 2015 Julie Terranova
*/

#include <pthread.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"
#include "X11/Xlib.h"
#include "philosophe.h"

SDL_Surface *load_image(char *filename)
{
  SDL_Surface* loadedImage;
  SDL_Surface* optimizedImage;

  loadedImage = NULL;
  optimizedImage = NULL;
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
  t_sdl	my_struct;

  my_struct.stick = NULL;
  my_struct.background = NULL;
  my_struct.screen = NULL;
  XInitThreads();
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (-1);
  if ((my_struct.screen = SDL_SetVideoMode(900, 600, 32, SDL_SWSURFACE)) == NULL)
    return (-1);
  SDL_WM_SetCaption("Graphic version - Philosophers", NULL);
  //Chargement des images:
  if ((my_struct.stick = load_image("pictures/stick.bmp")) == NULL)
    return (-1);
  if ((my_struct.background = load_image("pictures/background.bmp")) == NULL)
    return (-1);
  //On applique le fond sur l'écran:
  // apply_surface(0, 0, my_struct.background, my_struct.screen);
  // apply_surface(200, 425, my_struct.stick, my_struct.screen);
  // apply_surface(710, 425, my_struct.stick, my_struct.screen);

  if (SDL_Flip(my_struct.screen) == -1)
    return (-1);

  build(nb, &my_struct);

  //Libération des surfaces
  SDL_FreeSurface(my_struct.stick);
  SDL_FreeSurface(my_struct.background);

  SDL_Quit();
  return (0);
}
