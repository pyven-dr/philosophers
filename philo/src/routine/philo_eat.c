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

static int	check_philo_died(t_philosopher *philo)
{
	if (philo->philo_values[TIME_TO_EAT] >= philo->philo_values[TIME_TO_DIE])
	{
		wait_ms(philo->philo_values[TIME_TO_DIE]);
		pthread_mutex_lock(philo->dead_lock);
		if (*philo->philo_died == false)
			printf(PHILO_DIED, get_time() - philo->start_time, philo->id);
		*philo->philo_died = true;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	return (0);
}

int	philo_eat(t_philosopher *philo)
{
	if (take_forks(philo) == 1)
		return (1);
	if (print_state_change(PHILO_EAT, philo) == 1)
	{
		drop_one_fork(philo->left_fork);
		drop_one_fork(philo->right_fork);
		return (1);
	}
	philo->last_meal = get_time();
	if (check_philo_died(philo) == 1)
	{
		drop_one_fork(philo->left_fork);
		drop_one_fork(philo->right_fork);
		return (1);
	}
	wait_ms(philo->philo_values[TIME_TO_EAT]);
	drop_one_fork(philo->left_fork);
	drop_one_fork(philo->right_fork);
	if (philo->nb_eat > 0)
		philo->nb_eat--;
	return (0);
}
