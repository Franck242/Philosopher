/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "philo.h"

int	main(int ac, char **argv)
{
	t_check	*philo;
	int	nbp;
	int	nbe;

	philo = malloc(sizeof(*philo));
	if (philo == NULL)
		return (EXIT_ERROR);
	philo->first = NULL;
	check_all_param(ac, argv);
	RCFStartup(ac, argv);
	if (ac == 5) {
		nbp = atoi(argv[2]);
		nbe = atoi(argv[4]);
		eat_max = nbe;
		nbr_philos = nbp;
		simulate(philo);
	}
	RCFCleanup();
	return (SUCCESS_EXIT);
}
