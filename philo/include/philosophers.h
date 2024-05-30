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

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

# define NB_PHILO 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define NB_TIME_MUST_EAT 4

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
	t_fork			*righ_fork;
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
