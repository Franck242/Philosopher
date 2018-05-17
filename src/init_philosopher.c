/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "philo.h"

const t_status_action action[] = {{NONE, philosopher_eat},
				  {EAT, philosopher_rest},
				  {REST, philosopher_think}};


void	*gestion_of_status(void *addr)
{
	t_philo	*list = addr;

	while (list->eat_value < eat_max) {
		for (int j = 0; j < 3; j++) {
			if (action[j].status == list->status)
				list = action[j].f(list);
		}
		if (list->status == THINK)
			list->status = NONE;
	}
	return (NULL);
}

void	init_threads(t_check *cur)
{
	t_philo	*p;
	int	index;
	int	fd;

	index = 0;
	p = cur->first;
	while (index < nbr_philos) {
		fd = pthread_create(&p->phil_thread, NULL, gestion_of_status, p);
		if (fd) {
			_ERROR_DES_;
			exit(84);
		}
		p = p->next;
		index = index + 1;
	}
}

void	destroy_threads(t_check *cur)
{
	t_philo	*phil;
	int	index = 0;
	int	fd;

	phil = cur->first;
	while (index < nbr_philos) {
		fd = pthread_join(phil->phil_thread, NULL);
		if (fd) {
			_ERROR_DES_;
			exit(EXIT_ERROR);
		}
		index = index + 1;
		phil = phil->next;
	}
}

void	simulate(t_check *cur)
{
	create_list(cur);
	init_threads(cur);
	destroy_threads(cur);
}
