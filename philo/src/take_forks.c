/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 02:02:52 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/31 02:02:52 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_states.h"
#include "philosophers.h"

static void	take_one_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	while (fork->is_taken == true)
	{
		pthread_mutex_unlock(&fork->mutex);
		wait_ms(1);
		pthread_mutex_lock(&fork->mutex);
	}
	fork->is_taken = true;
	pthread_mutex_unlock(&fork->mutex);
}

void	drop_one_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_taken = false;
	pthread_mutex_unlock(&fork->mutex);
}

int	take_forks(t_philosopher *philosopher)
{
	take_one_fork(philosopher->left_fork);
	if (print_state_change(PHILO_FORK ,philosopher) == 1)
	{
		drop_one_fork(philosopher->left_fork);
		return (1);
	}
	take_one_fork(philosopher->right_fork);
	if (print_state_change(PHILO_FORK ,philosopher) == 1)
	{
		drop_one_fork(philosopher->left_fork);
		drop_one_fork(philosopher->right_fork);
		return (1);
	}
	return (0);
}