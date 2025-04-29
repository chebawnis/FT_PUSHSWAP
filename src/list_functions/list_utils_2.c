/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:24:56 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 21:25:52 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// retourne le nombre de noeuds d'une strucure
int	count_nodes(t_struct *head)
{
	int										i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

// retourne 1 si data est le min de head, 2 si data est le max de head, 0 sinon 
int	is_new_max_or_min(int data, t_struct *head)
{
	if (data < get_min(head))
		return (1);
	if (data > get_max(head))
		return (2);
	return (0);
}

// renvoie la plus grande valeur inferieure a data contenue dans head
int	get_higher_min(int data, t_struct *s2)
{
	int	res;

	res = get_min(s2);
	while (s2)
	{
		if (s2->data < data && s2->data > res)
			res = s2->data;
		s2 = s2->next;
	}
	return (res);
}

void	a(t_struct **head, int value, int i)
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
