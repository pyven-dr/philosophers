/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:08:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/30 00:08:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread(t_philo *st_philo, pthread_mutex_t *start_lock)
{
	int				i;

	i = 0;
	while (i < st_philo->philo_values[NB_PHILO])
	{
		st_philo->philo_list[i].start_lock = start_lock;
		if (pthread_create(&st_philo->philo_list[i].thread, NULL, \
		philo_routine, &st_philo->philo_list[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	join_thread(t_philo *st_philo)
{
	int	i;

	i = 0;
	while (i < st_philo->philo_values[NB_PHILO])
	{
		pthread_join(st_philo->philo_list[i].thread, NULL);
		i++;
	}
	return (0);
}

int	launch_sim(t_philo *st_philo)
{
	pthread_mutex_t	start_lock;

	if (pthread_mutex_init(&start_lock, NULL) != 0)
		return (1);
	pthread_mutex_lock(&start_lock);
	if (create_thread(st_philo, &start_lock) == 1)
	{
		pthread_mutex_unlock(&start_lock);
		pthread_mutex_destroy(&start_lock);
		return (1);
	}
	pthread_mutex_unlock(&start_lock);
	join_thread(st_philo);
	pthread_mutex_destroy(&start_lock);
	return (0);
}
