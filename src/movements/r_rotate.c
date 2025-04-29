/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:27:43 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 19:28:06 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_struct **head)
{
	t_struct								*tmp;
	t_struct								*tmp2;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *head;
	*head = tmp2;
}

void	r_r(t_struct **head, int i)
{
	if (i == 0)
		write(1, "rra\n", 4);
	else if (i == 1)
		write(1, "rrb\n", 4);
	r_rotate(head);
}

void	r_rr(t_struct **s1, t_struct **s2)
{
	r_rotate(s1);
	r_rotate(s2);
	write(1, "rrr\n", 4);
}
