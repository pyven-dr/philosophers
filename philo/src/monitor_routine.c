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
#include <stdio.h>

void	*monitor_routine(void *arg)
{
	t_philo	*st_philo;

	st_philo = (t_philo *)arg;
	printf("Monitoring thread created at %zu\n", get_time());
	pthread_mutex_unlock(st_philo->start_lock);
	return (NULL);
}
