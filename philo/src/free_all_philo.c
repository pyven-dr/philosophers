/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:44:54 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/30 01:44:54 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all_philo(t_philo *st_philo)
{
	int	i;

	i = 0;
	free(st_philo->philo_list);
	while (i < st_philo->philo_values[NB_PHILO])
	{
		pthread_mutex_destroy(&st_philo->fork_list[i].mutex);
		i++;
	}
	free(st_philo->fork_list);
}
