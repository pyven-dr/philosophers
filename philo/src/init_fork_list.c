/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:42:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/29 04:42:28 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_fork_list(t_philo *st_philo)
{
	t_fork	*fork_list;
	int		i;

	i = 0;
	fork_list = malloc(sizeof(t_fork) * st_philo->philo_values[NB_PHILO]);
	if (fork_list == NULL)
		return (1);
	while (i < st_philo->philo_values[NB_PHILO])
	{
		fork_list[i].is_taken = false;
		if (pthread_mutex_init(&fork_list[i].mutex, NULL) != 0)
			return (1);
		i++;
	}
	st_philo->fork_list = fork_list;
	return (0);
}
