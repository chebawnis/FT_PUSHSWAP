/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:20:48 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 19:28:25 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_struct **head)
{
	t_struct								*tmp1;
	t_struct								*tmp2;

	tmp1 = *head;
	if (!tmp1->next || !*head || !head)
		return ;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head = tmp2;
}

void	s(t_struct **head, int i)
{
	if (i == 0)
		write(1, "sa\n", 3);
	else if (i == 1)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
	swap(head);
}
