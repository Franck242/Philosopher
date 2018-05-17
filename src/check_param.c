/*
** EPITECH PROJECT, 2018
** check params
** File description:
** check params
*/

#include "philo.h"

void	print_usage(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "--help") == 0) {
		printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\n");
		printf("DESCRIPTION\n\t-p nbr_p number of philosophers\n");
		printf("\t-e nbr_e maximum number times a philosopher eats");
		printf(" before exitingthe program\n");
		exit(EXIT_ERROR);
	}
}

bool	is_num(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0') {
		if (str[index] > '9' || str[index] < '0')
			return (false);
		index = index + 1;
	}
	return (true);
}

void	check_all_param(int ac, char **av)
{
	int	e, p;

	print_usage(ac, av);
	if (ac < 5 || ac > 5) {
		_ERROR_ARG_;
		exit(EXIT_ERROR);
	}
	if (ac == 5) {
		e = atoi(av[4]);
		p = atoi(av[2]);
		if (e <= 0 || p < 2 || !is_num(av[4]) || !is_num(av[2])) {
			_ERROR_VALUE_;
			exit(EXIT_ERROR);
		}
		if (strcmp(av[1], "-p") != 0 || strcmp(av[3], "-e") != 0) {
			_ERROR_VALUE_;
			exit(EXIT_ERROR);
		}
	}
}
