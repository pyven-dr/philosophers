/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:08:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/30 00:08:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread(t_philo *st_philo, pthread_mutex_t *start_lock)
{
	int				i;

	i = 0;
	while (i < st_philo->philo_values[NB_PHILO])
	{
		st_philo->philo_list[i].start_lock = start_lock;
		if (pthread_create(&st_philo->philo_list[i].thread, NULL, \
		philo_routine, &st_philo->philo_list[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
