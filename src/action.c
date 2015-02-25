/*
** action.c for action in /home/moran-_d/rendu/PSU_2014_philo
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Mon Feb 16 11:08:03 2015 moran-_d
** Last update Wed Feb 25 20:36:08 2015 Julie Terranova
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "philosophe.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

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

  /* 0 = sleep ; 1 = eat ; 2 = think right ; 3 = think left */
  user_event.type = SDL_USEREVENT;
  user_event.user.code = action2; // useful?
  user_event.user.data1 = id;
  user_event.user.data2 = action;
  SDL_PushEvent(&user_event);
}

void think(philosophe *phi, int indic)
{
  int loop;

  if (indic == 1)
    {
      printf("Philosophe n°%d is thinking (Left)\n", phi->id);
      create_event(3, phi->id);
    }
  else
    {
      printf("Philosophe n°%d is thinking (Right)\n", phi->id);
      create_event(2, phi->id);
    }
  loop = 0;
  while (phi->baguette < 2 && loop < 40 && sleep(1) == 0)
    {
      if (indic == 1 && pthread_mutex_trylock(phi->right) == 0)
        phi->baguette += 1;
      else if (indic == 2 && pthread_mutex_trylock(phi->left) == 0)
        phi->baguette += 1;
    }
  if (phi->baguette == 2)
    eat(phi);
  else
    {
      printf("I'm thinking too much !\n");
      phi->baguette = 0;
      if (indic == 1)
        pthread_mutex_unlock(phi->left);
      else if (indic == 2)
        pthread_mutex_unlock(phi->right);
    }
}

void eat(philosophe *phi)
{
  printf("Philosophe n°%d is eating\n", phi->id);
  create_event(1, phi->id);
  sleep(5);
  pthread_mutex_unlock(phi->left);
  pthread_mutex_unlock(phi->right);
  printf("Philosophe n°%d is done eating\n", phi->id);
  phi->baguette = 0;
}

void try_to_think(philosophe *phi, int indic)
{
  if (indic == 0 && pthread_mutex_trylock(phi->left) == 0)
    indic = 1;
  else if (indic == 0 && pthread_mutex_trylock(phi->right) == 0)
    indic = 2;
  if (indic > 0)
    {
      phi->baguette = 1;
      think(phi, indic);
    }
}

void try_to_eat(philosophe *phi)
{
  int indic;

  indic = 0;
  if ((pthread_mutex_trylock(phi->left)) == 0)
    {
      phi->baguette += 1;
      indic = 1;
    }
  if ((pthread_mutex_trylock(phi->right)) == 0)
    {
      phi->baguette += 1;
      indic = 2;
    }
  if (phi->baguette == 2)
    eat(phi);
  else
    try_to_think(phi, indic);
}

void sleepphil(philosophe *phi)
{
  printf("Philosophe n°%d is sleeping\n", phi->id);
  create_event(0, phi->id);
  if (phi->baguette > 0)
    printf("Y'a un problème Descartes\n");
  sleep(5);
}
