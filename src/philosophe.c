/*
** philosophe.c for peuimporte in /home/terran_j/rendu/PSU_2014_philo
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Tue Feb 24 18:17:04 2015 Julie Terranova
** Last update Thu Feb 26 13:02:34 2015 moran-_d
*/

#include <pthread.h>
#include "SDL/SDL.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philosophe.h"

pthread_mutex_t *getMutex()
{
  static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

  return (&mutex);
}

int manageQuit(int i)
{
  static int quit = 0;

  if (i != 0)
    quit = i;
  return (quit);
}

void *action(void *phil)
{
  philosophe *phi;

  phi = (philosophe *)phil;
  pthread_mutex_lock(getMutex());
  pthread_mutex_unlock(getMutex());
  while (manageQuit(0) == 0)
    {
      try_to_eat(phi);
      sleepphil(phi);
    }
  pthread_exit(NULL);
}

philosophe *build_loop(int nb, philosophe **prev, pthread_t **thread_table)
{
  philosophe *phi;
  philosophe *start;

  start = NULL;
  while (nb > 0)
    {
      if ((phi = malloc(sizeof(*phi))) == NULL)
	return (NULL);
      phi->baguette = 0;
      phi->id = nb;
      if (start == NULL)
	start = phi;
      else
	{
	  if (((*prev)->left = malloc(sizeof(pthread_mutex_t))) == NULL)
	    return (NULL);
	  pthread_mutex_init((*prev)->left, NULL);
	  phi->right = (*prev)->left;
	}
      if (start != *prev && start != phi)
	pthread_create(&((*thread_table)[nb]), NULL, action, (void *)(*prev));
      *prev = phi;
      --nb;
    }
  return (start);
}

int proceed(int max, pthread_t *thread_table, t_sdl *my_struct)
{
  SDL_Event event;

  while (manageQuit(0) == 0)
    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
	manageQuit(1);
      else if (event.type == SDL_USEREVENT)
	if (move_picture(event.user.data1, event.user.data2, my_struct) == -1)
	  return (printf("Something went wrong with the SDL\n"));
  while (max >= 0)
    {
      pthread_join(thread_table[max], NULL);
      --max;
    }
  return (0);
}

int build(int nb, t_sdl *my_struct)
{
  int max;
  philosophe *prev;
  philosophe *start;
  pthread_t *thread_table;

  prev = NULL;
  max = nb - 1;
  if ((thread_table = malloc(sizeof(*thread_table) * nb)) == NULL)
    return (-1);
  pthread_mutex_lock(getMutex());
  if ((start = build_loop(nb, &prev, &thread_table)) == NULL)
    {
      pthread_mutex_unlock(getMutex());
      return (-1);
    }
  if ((prev->left = malloc(sizeof(pthread_mutex_t))) == NULL)
    return (-1);
  pthread_mutex_init(prev->left, NULL);
  start->right = prev->left;
  pthread_create(&(thread_table[0]), NULL, action, (void *)prev);
  pthread_create(&(thread_table[max]), NULL, action, (void *)start);
  pthread_mutex_unlock(getMutex());
  return (proceed(max, thread_table, my_struct));
}

int main(int argc, char **argv)
{
  int nb;

  if (argc < 2)
    nb = 7;
  else if ((nb = atoi(argv[1])) < 3)
    {
      printf("Need at least 3 philosophers\n");
      return (-1);
    }
  else if (nb > 50)
    {
      printf("Nice try\n");
      return (-1);
    }
  if (draw(nb) == -1)
    return (printf("Something went wrong with the SDL\n"));
  return (0);
}
