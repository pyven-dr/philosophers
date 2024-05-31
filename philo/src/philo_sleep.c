/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:09:12 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/31 01:09:12 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_states.h"

int	philo_sleep(t_philosopher *philosopher)
{
	print_state_change(PHILO_SLEEP, philosopher);
	wait_ms(philosopher->philo_values[TIME_TO_SLEEP]);
	return (0);
}
