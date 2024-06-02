/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_died.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 02:47:30 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/06/02 02:47:30 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "philosophers.h"

static int	philo_died(int i, t_philo *st_philo)
{
	pthread_mutex_lock(st_philo->dead_lock);
	st_philo->philo_died = true;
	pthread_mutex_unlock(st_philo->dead_lock);
	printf(PHILO_DIED, get_time() - st_philo->start_time, i + 1);
	return (1);
}

static int	check_nb_eat(int philo_nb_eat, t_philo *st_philo)
{
	if (philo_nb_eat == 0 && st_philo->philo_values[NB_TIME_MUST_EAT] != -1)
	{
		pthread_mutex_lock(st_philo->dead_lock);
		st_philo->philo_died = true;
		pthread_mutex_unlock(st_philo->dead_lock);
		return (1);
	}
	return (0);
}

int	check_philo_died(t_philo *st_philo)
{
	int	i;
	int	philo_nb_eat;

	i = 0;
	philo_nb_eat = 0;
	while (i < st_philo->philo_values[NB_PHILO])
	{
		pthread_mutex_lock(&st_philo->philo_list[i].last_meal_lock);
		if (get_time() - st_philo->philo_list[i].last_meal >= \
			(size_t)st_philo->philo_values[TIME_TO_DIE])
		{
			pthread_mutex_unlock(&st_philo->philo_list[i].last_meal_lock);
			return (philo_died(i, st_philo));
		}
		pthread_mutex_unlock(&st_philo->philo_list[i].last_meal_lock);
		pthread_mutex_lock(&st_philo->philo_list[i].nb_eat_lock);
		if (st_philo->philo_values[NB_TIME_MUST_EAT] != -1)
			philo_nb_eat += st_philo->philo_list[i].nb_eat;
		pthread_mutex_unlock(&st_philo->philo_list[i].nb_eat_lock);
		i++;
	}
	return (check_nb_eat(philo_nb_eat, st_philo));
}
