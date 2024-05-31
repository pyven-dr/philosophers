/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:48:55 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/30 00:48:55 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_states.h"

void	*philo_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	pthread_mutex_lock(philosopher->start_lock);
	philosopher->last_meal = *philosopher->start_time;
	pthread_mutex_unlock(philosopher->start_lock);
	if (philosopher->id % 2 == 0)
	{
		philo_eat(philosopher);
		philo_sleep(philosopher);
		print_state_change(PHILO_THINK, philosopher);
	}
	else
	{
		print_state_change(PHILO_THINK, philosopher);
		wait_ms(philosopher->philo_values[TIME_TO_EAT] + 10);
		philo_eat(philosopher);
		philo_sleep(philosopher);
	}
	return (NULL);
}
