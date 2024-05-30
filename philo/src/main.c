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

int	main(int argc, char **argv)
{
	t_philo			philo_struct;
	pthread_mutex_t	dead_lock;

	if (parsing(argc, argv, &philo_struct) == 1)
		return (1);
	if (init_all_philos(&philo_struct, &dead_lock) == 1)
		return (1);
	if (launch_sim(&philo_struct) == 1)
		return (1);
	pthread_mutex_destroy(&dead_lock);
	free_all_philo(&philo_struct);
	return (0);
}
