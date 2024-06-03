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
	wait_ms(st_philo->philo_values[TIME_TO_EAT / 2]);
	while (true)
		if (check_philo_died(st_philo) == 1)
			return (NULL);
}
