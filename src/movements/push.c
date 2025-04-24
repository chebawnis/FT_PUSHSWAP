/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:07:50 by adichou           #+#    #+#             */
/*   Updated: 2025/04/22 17:08:41 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_struct **from, t_struct **to)
{
    t_struct *tmp;

	if (from && *from)
	{
	    tmp = *from;
	    *from = (*from)->next;
		tmp->next = *to;
		*to = tmp;
	}
}

void	p(t_struct **from, t_struct **to, int i)
{
	push(from, to);
	if (i == 0)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}