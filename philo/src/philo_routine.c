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
#include <stdio.h>

void	*philo_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	pthread_mutex_lock(philosopher->start_lock);
	printf("Thread %d created at %zu\n", philosopher->id, get_time());
	pthread_mutex_unlock(philosopher->start_lock);
	return (NULL);
}
