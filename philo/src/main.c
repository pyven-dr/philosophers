/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:36 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/24 15:55:36 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_philo philo_struct;

	if (parsing(argc, argv, &philo_struct) == 1)
		return (1);
	printf("nb_philo : %d time_to_die : %d time_to_eat : %d time_to_sleep : %d nb_eat : %d\n", \
			philo_struct.philo_values[NB_PHILO], philo_struct.philo_values[TIME_TO_DIE], philo_struct.philo_values[TIME_TO_EAT], philo_struct.philo_values[TIME_TO_SLEEP], philo_struct.philo_values[NB_TIME_MUST_EAT]);
	return (0);
}