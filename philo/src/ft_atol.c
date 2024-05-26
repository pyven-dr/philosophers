/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:35:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/26 22:35:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_parsing.h"
#include <limits.h>

static long int	return_value(int min)
{
	if (min == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long int	ft_atol(const char *nptr)
{
	size_t		i;
	long int	res;
	int			min;

	i = 0;
	res = 0;
	min = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			min = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - 48);
		if (res < 0)
			return (return_value(min));
		i++;
	}
	return (res * min);
}
