/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:09:08 by adichou           #+#    #+#             */
/*   Updated: 2025/04/13 05:00:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_indexes(t_struct **head)
{
	t_struct								*tmp;
	int										i;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i ++;
	}
}

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
	tmp = *head;
	update_indexes(head);
}

void	r_rotate(t_struct **head)
{
	t_struct								*tmp;
	t_struct								*tmp2;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *head;
	*head = tmp2;
	tmp = *head;
	update_indexes(head);
}

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
	update_indexes(head);
}

void push(t_struct **from, t_struct **to)
{
    t_struct *tmp;
    t_struct *current;
    int i;

    if (!from || !*from)
        return;
    tmp = *from;
    *from = tmp->next;
    i = 0;
    current = *from;
    while (current)
    {
        current->index = i;
        current = current->next;
        i++;
    }
    tmp->next = *to;
    *to = tmp;
    i = 0;
    current = *to;
    while (current)
    {
        current->index = i;
        current = current->next;
        i++;
    }
}

