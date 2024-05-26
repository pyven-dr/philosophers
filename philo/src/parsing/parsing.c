/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:19:35 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/26 22:19:35 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_parsing.h"
#include "philosophers.h"
#include <limits.h>

int	fill_struct(int argc, char **argv, t_philo *philo_struct)
{
	int		i;
	long	temp;

	i = 1;
	while (argv[i] != NULL)
	{
		temp = ft_atol(argv[i]);
		if (temp > INT_MAX || temp < 1)
		{
			write(STDERR_FILENO, NON_VALID_ARG, 58);
			return (1);
		}
		philo_struct->philo_values[i - 1] = (int)temp;
		i++;
	}
	if (argc == 5)
		philo_struct->philo_values[NB_TIME_MUST_EAT] = 0;
	return (0);
}

int	parsing(int argc, char **argv, t_philo *philo_struct)
{
	if ((argc == 5 || argc == 6) && check_args(argv) == 0)
		return (fill_struct(argc, argv, philo_struct));
	if (argc < 5)
	{
		write(STDERR_FILENO, TOO_FEW_ARGS, 33);
		return (1);
	}
	if (argc > 6)
	{
		write(STDERR_FILENO, TOO_MUCH_ARGS, 34);
		return (1);
	}
	return (1);
}