/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:12:35 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 21:35:31 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// renvoie la position du noeud contenant data dans head
int	get_pos(t_struct *head, int data)
{
	int	i;

	i = 0;
	while (head->next && head->data != data)
	{
		i ++;
		head = head->next;
	}
	return (i);
}

// retourne 0 si la liste n'est pas triee, 1 si elle l'est deja
int	is_sorted(t_struct *head)
{
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

// retourne le data min contenu dans la structure
int	get_min(t_struct *head)
{
	int		min;

	min = head->data;
	while (head)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}

// retourne le data max contenu dans la structure
int	get_max(t_struct *head)
{
	int		max;

	max = head->data;
	while (head)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}

void	get_in_top(t_struct **head, int value, int i)
{
	if (is_under(count_nodes(*head), get_pos(*head, value)))
	{
		while (get_pos(*head, value))
			r(head, i);
	}
	else
	{
		while (get_pos(*head, value))
			r_r(head, i);
	}
}
