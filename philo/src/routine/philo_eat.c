/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 04:57:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/30 04:57:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_states.h"

int	philo_eat(t_philosopher *philosopher)
{
	if (take_forks(philosopher) == 1)
		return (1);
	if (print_state_change(PHILO_EAT, philosopher) == 1)
	{
		drop_one_fork(philosopher->left_fork);
		drop_one_fork(philosopher->right_fork);
		return (1);
	}
	pthread_mutex_lock(&philosopher->next_meal_lock);
	philosopher->next_meal = get_time() + \
							philosopher->philo_values[TIME_TO_DIE];
	pthread_mutex_unlock(&philosopher->next_meal_lock);
	wait_ms(philosopher->philo_values[TIME_TO_EAT]);
	drop_one_fork(philosopher->left_fork);
	drop_one_fork(philosopher->right_fork);
	pthread_mutex_lock(&philosopher->nb_eat_lock);
	if (philosopher->nb_eat > 0)
		philosopher->nb_eat--;
	pthread_mutex_unlock(&philosopher->nb_eat_lock);
	return (0);
}
