/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:17:21 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/31 01:17:21 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STATES_H
# define PHILO_STATES_H

# include <stdio.h>
# include "philo_struct.h"

# define PHILO_SLEEP "\e[34m%zu %d is sleeping\n\e[0m"
# define PHILO_THINK "\e[32m%zu %d is thinking\n\e[0m"
# define PHILO_FORK "\e[35m%zu %d has taken a fork\n\e[0m"
# define PHILO_EAT "\e[33m%zu %d is eating\n\e[0m"
# define PHILO_DIED "\e[31m%zu %d died\n\e[0m"

int		philo_sleep(t_philosopher *philosopher);
int		philo_eat(t_philosopher *philo);
void	drop_one_fork(t_fork *fork);
int		take_forks(t_philosopher *philosopher);
int		print_state_change(char *state, t_philosopher *philosopher);

#endif
