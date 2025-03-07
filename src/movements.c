/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:09:08 by adichou           #+#    #+#             */
/*   Updated: 2025/03/07 03:05:12 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_struct **head)
{
	t_struct								*first;
	t_struct								*tmp;
	int										i;

	if (*head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	i = 0;
	*head = first->next;
	first->next = NULL;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i ++;
	}
}

void	r_rotate(t_struct **head)
{
	t_struct								*tmp;
	t_struct								*tmp2;
	int										i;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	tmp = *head;
	i = 0;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *head;
	*head = tmp2;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i ++;
	}
}

void	swap(t_struct **head)
{
	t_struct								*tmp;
	t_struct								*tmp2;
	int										i;

	tmp = *head;
	i = 0;
	while (tmp->next->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i ++;
	}
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

