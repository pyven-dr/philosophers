/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 02:54:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/06/02 02:54:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "monitor.h"

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
		pthread_mutex_lock(st_philo->dead_lock);
		st_philo->philo_died = true;
		pthread_mutex_unlock(st_philo->dead_lock);
		pthread_mutex_unlock(&start_lock);
		pthread_mutex_destroy(&start_lock);
		return (1);
	}
	if (create_monitoring(st_philo, &start_lock) == 1)
	{
		join_thread(st_philo);
		return (1);
	}
	join_thread(st_philo);
	pthread_mutex_destroy(&start_lock);
	return (0);
}
