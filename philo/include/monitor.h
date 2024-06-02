/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 02:51:01 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/06/02 02:51:01 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include "philo_struct.h"
# include <stdio.h>

# define PHILO_DIED "\e[31m%zu %d died\n\e[0m"

int		check_philo_died(t_philo *st_philo);
void	*monitor_routine(void *arg);
int		create_monitoring(t_philo *st_philo, pthread_mutex_t *start_lock);

#endif
