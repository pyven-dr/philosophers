/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:52:37 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/27 15:52:37 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_philosopher *philo, t_philo *st_philo, int i)
{
	philo->id = i + 1;
	philo->philo_values = st_philo->philo_values;
	philo->dead_lock = st_philo->dead_lock;
	philo->philo_died = &st_philo->philo_died;
	philo->left_fork = &st_philo->fork_list[i];
	if (i == st_philo->philo_values[NB_PHILO] - 1)
		philo->righ_fork = &st_philo->fork_list[0];
	else
		philo->righ_fork = &st_philo->fork_list[i + 1];
}

int	init_all_philos(t_philo *st_philo, pthread_mutex_t *dead_lock)
{
	int	i;

	i = 0;
	pthread_mutex_init(dead_lock, NULL);
	st_philo->philo_list = malloc(\
	sizeof(t_philosopher) * st_philo->philo_values[NB_PHILO]);
	if (st_philo->philo_list == NULL)
		return (1);
	if (init_fork_list(st_philo) == 1)
	{
		free(st_philo->philo_list);
		return (1);
	}
	st_philo->dead_lock = dead_lock;
	st_philo->philo_died = false;
	while (i < st_philo->philo_values[NB_PHILO])
	{
		init_philo(&st_philo->philo_list[i], st_philo, i);
		i++;
	}
	return (0);
}
