/*
** philosophe.h for philosophe in /home/moran-_d/rendu/PSU_2014_philo
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Mon Feb 16 10:33:51 2015 moran-_d
** Last update Tue Feb 17 09:13:15 2015 moran-_d
*/

#ifndef PHILOSOPHE_H_
#define PHILOSOPHE_H_

typedef struct s_philosophe
{
  int id;
  int baguette;
  pthread_mutex_t *left;
  pthread_mutex_t *right;
} philosophe;

void think(philosophe *phi, int indic);
void eat(philosophe *phi);
void try_to_think(philosophe *phi, int indic);
void try_to_eat(philosophe *phi);
void sleepphil(philosophe *phi);

#endif
