/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:57:54 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/26 22:57:54 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_parsing.h"

static int	is_arg_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_arg_num(argv[i]) == 1)
		{
			if (write(STDERR_FILENO, NON_NUMERIC_ARG, 26) != 26)
				return (1);
			return (1);
		}
		i++;
	}
	return (0);
}
