/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 02:19:23 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/31 02:19:23 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool			is_taken;
}	t_fork;

typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	int				*philo_values;
	size_t			*start_time;
	size_t			last_meal;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*start_lock;
	pthread_mutex_t	*dead_lock;
	bool			*philo_died;

}	t_philosopher;

typedef struct s_philo
{
	int				philo_values[5];
	size_t			start_time;
	t_philosopher	*philo_list;
	t_fork			*fork_list;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*start_lock;
	bool			philo_died;
}	t_philo;

#endif
