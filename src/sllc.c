/*
** EPITECH PROJECT, 2018
** sllc
** File description:
** linked list
*/

#include "philo.h"

t_philo *init_philo(int num)
{
	t_philo *res;

	res = malloc(sizeof(t_philo));
	if (res == NULL) {
		write(2, "Error on allocation mem\n", 26);
		exit(EXIT_ERROR);
	}
	res->num_philo = num;
	res->status = 3;
	res->eat_value = 0;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_philo *add_elem(t_check *first, int num)
{
	t_philo	*new, *cur, *cur1;

	new = init_philo(num);
	cur = first->first;
	if (!cur) {
		first->first = new;
	}
	else {
		while (cur->next != NULL)
			cur = cur->next;
		new->prev = cur;
		cur->next = new;
		if (num + 1 == nbr_philos) {
			cur1 = first->first;
			new->next = first->first;
			cur1->prev = new;
		}
	}
	return (new);
}

t_philo *create_list(t_check *philo)
{
	t_philo *res;
	int	index = 0;

	while (index < nbr_philos) {
		res = add_elem(philo, index);
		index = index + 1;
	}
	return (res);
}
