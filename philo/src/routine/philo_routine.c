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

static int	init_philo_routine(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->start_lock);
	pthread_mutex_unlock(philosopher->start_lock);
	philosopher->start_time = get_time();
	pthread_mutex_lock(&philosopher->next_meal_lock);
	philosopher->next_meal = philosopher->start_time + \
							philosopher->philo_values[TIME_TO_DIE];
	pthread_mutex_unlock(&philosopher->next_meal_lock);
	if (philosopher->id % 2 == 1)
	{
		if (print_state_change(PHILO_THINK, philosopher) == 1)
			return (1);
		wait_ms(philosopher->philo_values[TIME_TO_EAT] / 2);
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (init_philo_routine(philosopher) == 1)
		return (NULL);
	while (true)
	{
		if (philo_eat(philosopher) == 1)
			return (NULL);
		if (philo_sleep(philosopher) == 1)
			return (NULL);
		if (print_state_change(PHILO_THINK, philosopher) == 1)
			return (NULL);
	}
}
