/*
** philosophe.h for philosophe in /home/moran-_d/rendu/PSU_2014_philo
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Mon Feb 16 10:33:51 2015 moran-_d
** Last update Thu Feb 26 20:36:37 2015 Julie Terranova
*/

#ifndef PHILOSOPHE_H_
# define PHILOSOPHE_H_

#include <pthread.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

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

typedef struct s_ttf
{
  SDL_Surface	*msg;
  TTF_Font      *font;
  SDL_Color     txtColor;
  char          *str;
} t_ttf;

pthread_mutex_t *getMutex();
int manageQuit(int i);
void think(philosophe *phi, int indic);
void eat(philosophe *phi);
void try_to_think(philosophe *phi, int indic);
void try_to_eat(philosophe *phi);
void sleepphil(philosophe *phi);
int build(int nb, t_sdl *my_struct);
int draw(int nb);
int move_picture(int *id, int *action, t_sdl *my_struct);
void apply_surface(int, int, SDL_Surface*, SDL_Surface*);
void create_event(int action2, int id2);
void sleeps(t_sdl *mine, int *id, t_ttf sent);
void eats(t_sdl *mine, int *id, t_ttf sent);
void thinksleft(t_sdl *mine, int *id, t_ttf sent);
void thinksright(t_sdl *mine, int *id, t_ttf sent);

#endif
