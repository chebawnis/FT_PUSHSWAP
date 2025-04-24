/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:21:24 by adichou           #+#    #+#             */
/*   Updated: 2025/04/22 17:20:19 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_struct **head)
{
	t_struct								*first;
	t_struct								*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	*head = first->next;
	first->next = NULL;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
}

void	r(t_struct **head, int i)
{
	if (i == 0)
		write(1, "ra\n", 3);
	else if (i == 1)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
	
	rotate(head);
}