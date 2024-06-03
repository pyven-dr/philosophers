/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 02:09:05 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/31 02:09:05 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_states.h"
#include "philosophers.h"

int	print_state_change(char *state, t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->dead_lock);
	if (*philosopher->philo_died == true)
	{
		pthread_mutex_unlock(philosopher->dead_lock);
		return (1);
	}
	printf(state, get_time() - philosopher->start_time, philosopher->id);
	pthread_mutex_unlock(philosopher->dead_lock);
	return (0);
}
