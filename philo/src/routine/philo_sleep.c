/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:09:12 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/31 01:09:12 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_states.h"

int	philo_sleep(t_philosopher *philo)
{
	size_t	time_no_eat;
	size_t	current_time;

	current_time = get_time();
	if (print_state_change(PHILO_SLEEP, philo) == 1)
		return (1);
	time_no_eat = current_time - philo->last_meal + \
				philo->philo_values[TIME_TO_SLEEP];
	if (time_no_eat >= (size_t)philo->philo_values[TIME_TO_DIE])
	{
		wait_ms(philo->philo_values[TIME_TO_DIE] - \
				(current_time - philo->start_time));
		pthread_mutex_lock(philo->dead_lock);
		if (*philo->philo_died == false)
			printf(PHILO_DIED, get_time() - philo->start_time, philo->id);
		*philo->philo_died = true;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	wait_ms(philo->philo_values[TIME_TO_SLEEP]);
	return (0);
}
