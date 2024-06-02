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

#include "monitor.h"
#include "philosophers.h"

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
