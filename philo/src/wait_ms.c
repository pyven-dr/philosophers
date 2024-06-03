/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:10:21 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/30 05:10:21 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_ms(size_t ms)
{
	size_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < ms)
		usleep(50);
}
