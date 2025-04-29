/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:27:43 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 21:27:54 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_under(int len, int indice)
{
	if (indice <= len / 2)
		return (1);
	return (0);
}

int	is_over(int len, int indice)
{
	if (indice > len / 2)
		return (1);
	return (0);
}

int	cmp_int(int index_1, int index_2)
{
	if (index_1 > index_2)
		return (index_1);
	return (index_2);
}

int	cmp_min_int(int index_1, int index_2)
{
	if (index_1 > index_2)
		return (index_2);
	return (index_1);
}

void	init_target(int *target)
{
	target[0] = 0;
	target[1] = 0;
	target[2] = 0;
}
