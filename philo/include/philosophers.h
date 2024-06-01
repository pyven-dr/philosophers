/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/24 16:00:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "philo_struct.h"
# include <unistd.h>
# include <stdlib.h>

# define NB_PHILO 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define NB_TIME_MUST_EAT 4
# define PHILO_DIED "\e[31m%zu %d died\n\e[0m"

int		parsing(int argc, char **argv, t_philo *philo_struct);
size_t	get_time(void);
int		init_fork_list(t_philo *st_philo);
int		init_all_philos(t_philo *st_philo, pthread_mutex_t *dead_lock);
void	*philo_routine(void *arg);
int		launch_sim(t_philo *st_philo);
void	free_all_philo(t_philo *st_philo);
void	*monitor_routine(void *arg);
void	wait_ms(size_t ms);

#endif
