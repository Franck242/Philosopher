/*
** EPITECH PROJECT, 2018
** philo
** File description:
** header
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include "extern.h"

typedef enum		status
{
	THINK,
	EAT,
	REST,
	NONE
}			t_status;

typedef struct		s_philo
{
	t_status	status;
	struct s_philo	*next;
	struct s_philo	*prev;
	int		num_philo;
	pthread_mutex_t	chopstick;
	pthread_t	phil_thread;
	int		eat_value;
}			t_philo;

typedef struct		s_check
{
	t_philo		*first;
}			t_check;

typedef struct		s_status_action
{
	t_status	status;
	t_philo*	(*f)(t_philo*);
}			t_status_action;

# define EXIT_ERROR	(84)
# define SUCCESS_EXIT	(0)
# define _ERROR_ARG_	write(2, "Too few or too many arguments\n", 31);
# define _ERROR_VALUE_	write(2, "Error on flags or values\n", 26);
# define _ERROR_THREAD_	write(2, "Error of created threads\n", 26);
# define _ERROR_DES_	write(2, "Error on threads join.\n", 24);

int	nbr_philos;
int	eat_max;

void	check_all_param(int ac, char **av);
void	init_threads(t_check *cur);
void	*gestion_status(void *addr);
t_philo	*philosopher_rest(t_philo *current);
t_philo	*philosopher_think(t_philo *current);
t_philo	*philosopher_eat(t_philo *current);
void	destroy_threads(t_check *cur);
t_philo	*create_list(t_check *philo);
t_philo	*init_philo(int num);
t_philo	*add_elem(t_check *first, int num);
t_philo	*create_list(t_check *philo);
void	simulate(t_check *cur);

#endif /* PHILO_H */
