/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:55:52 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 21:36:30 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	find_hunter_and_target(t_struct *s1, t_struct *s2, int *targets)
{
	int		target;
	int		shot_tmp;
	int		i;

	i = 0;
	while (s1)
	{
		if (is_new_max_or_min(s1->data, s2) != 0)
			target = get_max(s2);
		else
			target = get_higher_min(s1->data, s2);
		if (!i && !get_pos(s2, targets[1]) && !targets[2])
			shot_tmp = 1;
		else
			shot_tmp = get_number_shot(count_nodes(s1) + i,
					count_nodes(s2), i, get_pos(s2, target));
		if (shot_tmp < targets[2] || !targets[2])
		{
			targets[0] = s1->data;
			targets[1] = target;
			targets[2] = shot_tmp;
		}
		s1 = s1->next;
		i ++;
	}
}

void	push_to_s2_bis(t_struct **s1, t_struct **s2, int targets[3])
{
	while (get_pos(*s1, targets[0]))
	{
		if (get_pos(*s1, targets[0]) <= count_nodes(*s1) / 2)
			r(s1, 0);
		else
			r_r(s1, 0);
	}
	while (get_pos(*s2, targets[1]))
	{
		if (get_pos(*s2, targets[1]) <= count_nodes(*s2) / 2)
			r(s2, 1);
		else
			r_r(s2, 1);
	}
}

void	push_to_s2(t_struct **s1, t_struct **s2, int targets[3])
{
	if (under(count_nodes(*s1), count_nodes(*s2),
			get_pos(*s1, targets[0]), get_pos(*s2, targets[1])))
	{
		while (get_pos(*s1, targets[0]) && get_pos(*s2, targets[1]))
			rr(s1, s2);
	}
	else if (over(count_nodes(*s1), count_nodes(*s2),
			get_pos(*s1, targets[0]), get_pos(*s2, targets[1])))
	{
		while (get_pos(*s1, targets[0]) && get_pos(*s2, targets[1]))
			r_rr(s1, s2);
	}
	push_to_s2_bis(s1, s2, targets);
	p(s1, s2, 1);
}

void	reverse_sort_to_b(t_struct **s1, t_struct **s2)
{
	int	targets[3];

	init_target(&targets[0]);
	find_hunter_and_target(*s1, *s2, &targets[0]);
	push_to_s2(s1, s2, targets);
}
