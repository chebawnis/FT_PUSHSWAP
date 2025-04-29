/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_shot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:17:22 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 21:34:57 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	under(int size_s1, int size_s2, int hntr, int trg)
{
	if ((is_under(size_s1, hntr) && is_under(size_s2, trg))
		|| (is_under(size_s1, hntr) && is_over(size_s2, trg)
			&& cmp_int(hntr, trg) <= cmp_int(size_s1 - hntr, size_s2 - trg)
			&& cmp_int(hntr, trg) <= size_s2 - trg + hntr)
		|| (is_under(size_s2, trg) && is_over(size_s1, hntr)
			&& cmp_int(hntr, trg) <= cmp_int(size_s1 - hntr, size_s2 - trg)
			&& cmp_int(hntr, trg) <= size_s1 - hntr + trg))
		return (cmp_int(hntr, trg) + 1);
	return (0);
}

int	over(int size_s1, int size_s2, int hntr, int trg)
{
	if ((is_over(size_s1, hntr) && is_over(size_s2, trg))
		|| (is_under(size_s1, hntr) && is_over(size_s2, trg)
			&& cmp_int(hntr, trg) >= cmp_int(size_s1 - hntr, size_s2 - trg)
			&& cmp_int(size_s1 - hntr, size_s2 - trg) <= size_s2 - trg + hntr)
		|| (is_under(size_s2, trg) && is_over(size_s1, hntr)
			&& cmp_int(hntr, trg) >= cmp_int(size_s1 - hntr, size_s2 - trg)
			&& cmp_int(size_s1 - hntr, size_s2 - trg) <= size_s1 - hntr + trg))
		return (cmp_int(size_s1 - hntr, size_s2 - trg) + 1);
	return (0);
}

int	get_number_shot(int size_s1, int size_s2, int hunter, int target)
{
	int		shot;

	shot = under(size_s1, size_s2, hunter, target);
	if (!shot)
		shot = over(size_s1, size_s2, hunter, target);
	if (!shot)
	{
		if (is_under(size_s1, hunter))
			shot = hunter + size_s2 - target + 1;
		else
			shot = target + size_s1 - hunter + 1;
	}
	return (shot);
}
