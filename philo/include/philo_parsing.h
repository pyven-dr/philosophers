/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:24:02 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/26 22:24:02 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PARSING_H
# define PHILO_PARSING_H

#include <unistd.h>

# define TOO_MUCH_ARGS "Too many arguments need 5 maximum\n"
# define TOO_FEW_ARGS "Too few arguments need 4 minimum\n"
# define NON_NUMERIC_ARG "Arguments must be numeric\n"
# define NON_VALID_ARG \
		"Arguments can't be greater than INT_MAX or smaller than 1\n"

long int	ft_atol(const char *nptr);
int			ft_isdigit(int c);
int			check_args(char **argv);

#endif
