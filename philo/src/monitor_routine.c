/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 03:48:49 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/30 03:48:49 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_struct.h"
#include <stdio.h>

int	check_philo_died(t_philo *st_philo)
{
	int	i;

	i = 0;
	while (i < st_philo->philo_values[NB_PHILO])
	{
		pthread_mutex_lock(&st_philo->philo_list[i].last_meal_lock);
		if (get_time() - st_philo->philo_list[i].last_meal >= \
			(size_t)st_philo->philo_values[TIME_TO_DIE])
		{
			pthread_mutex_unlock(&st_philo->philo_list[i].last_meal_lock);
			pthread_mutex_lock(st_philo->dead_lock);
			st_philo->philo_died = true;
			pthread_mutex_unlock(st_philo->dead_lock);
			printf(PHILO_DIED, get_time() - st_philo->start_time, i + 1);
			return (1);
		}
		pthread_mutex_unlock(&st_philo->philo_list[i].last_meal_lock);
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*st_philo;

	st_philo = (t_philo *)arg;
	st_philo->start_time = get_time();
	pthread_mutex_unlock(st_philo->start_lock);
	wait_ms(50);
	while (true)
		if (check_philo_died(st_philo) == 1)
			return (NULL);
}
