/*
** manage_static.c for static in /home/moran-_d/rendu/PSU_2014_philo
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Thu Feb 26 13:08:05 2015 moran-_d
** Last update Thu Feb 26 13:08:20 2015 moran-_d
*/

#include <pthread.h>

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
