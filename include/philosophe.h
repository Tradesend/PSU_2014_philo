/*
** philosophe.h for philosophe in /home/moran-_d/rendu/PSU_2014_philo
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Mon Feb 16 10:33:51 2015 moran-_d
** Last update Thu Feb 26 12:55:14 2015 moran-_d
*/

#ifndef PHILOSOPHE_H_
# define PHILOSOPHE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

typedef struct s_philosophe
{
  int id;
  int baguette;
  pthread_mutex_t *left;
  pthread_mutex_t *right;
} philosophe;

typedef struct s_sdl
{
  SDL_Surface *stick;
  SDL_Surface *background;
  SDL_Surface *screen;
} t_sdl;

void think(philosophe *phi, int indic);
void eat(philosophe *phi);
void try_to_think(philosophe *phi, int indic);
void try_to_eat(philosophe *phi);
void sleepphil(philosophe *phi);
int build(int nb, t_sdl *my_struct);
int draw(int nb);
int move_picture(int *id, int *action, t_sdl *my_struct);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
void create_event(int action2, int id2);

#endif
