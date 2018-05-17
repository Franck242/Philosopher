/*
** EPITECH PROJECT, 2018
** actions
** File description:
** actions
*/

#include "philo.h"

t_philo	*try_to_lock(t_philo *current)
{
	pthread_mutex_trylock(&current->chopstick);
	pthread_mutex_trylock(&current->next->chopstick);
	lphilo_take_chopstick(&current->next->chopstick);
	lphilo_take_chopstick(&current->chopstick);
	return (current);
}

t_philo	*unlock_that(t_philo *current)
{
	pthread_mutex_unlock(&current->chopstick);
	pthread_mutex_unlock(&current->next->chopstick);
	lphilo_release_chopstick(&current->chopstick);
	lphilo_release_chopstick(&current->next->chopstick);
	return (current);
}

t_philo	*philosopher_rest(t_philo *current)
{
	lphilo_sleep();
	current->status = 2;
	current->eat_value++;
	return (current);
}

t_philo	*philosopher_eat(t_philo *current)
{
	try_to_lock(current);
	lphilo_eat();
	current->status = 1;
	unlock_that(current);
	return (current);
}

t_philo	*philosopher_think(t_philo *current)
{
	pthread_mutex_trylock(&current->chopstick);
	lphilo_take_chopstick(&current->chopstick);
	lphilo_think();
	pthread_mutex_unlock(&current->chopstick);
	lphilo_release_chopstick(&current->chopstick);
	current->status = 0;
	return (current);
}
