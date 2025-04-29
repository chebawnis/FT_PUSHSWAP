/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:08:04 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 21:34:44 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_three(t_struct **stack)
{
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		s(stack, 0);
		r(stack, 0);
	}
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->data > (*stack)->next->next->data)
		r_r(stack, 0);
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data)
		s(stack, 0);
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->data < (*stack)->next->next->data)
		r(stack, 0);
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		r(stack, 0);
		s(stack, 0);
	}
}

void	sort_3(t_struct **stack, int len)
{
	if (len == 2 && (*stack)->data > (*stack)->next->data)
		r(stack, 0);
	if (len == 3)
		ft_sort_three(stack);
}

int	get_lower_max(int data, t_struct *s2)
{
	int	res;

	res = get_max(s2);
	while (s2)
	{
		if (s2->data > data && s2->data < res)
			res = s2->data;
		s2 = s2->next;
	}
	return (res);
}

void	final_placement(t_struct **s1, t_struct **s2)
{
	int			target;

	while (*s2)
	{
		if (is_new_max_or_min((*s2)->data, *s1))
			target = get_min(*s1);
		else
			target = get_lower_max((*s2)->data, *s1);
		get_in_top(s1, target, 0);
		p(s2, s1, 0);
	}
}
