/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:40:58 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 21:36:58 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_struct **head, t_struct **s2)
{
	if (!is_sorted(*head))
	{
		if (count_nodes(*head) < 4)
			sort_3(head, count_nodes(*head));
		else
		{
			p(head, s2, 1);
			p(head, s2, 1);
			while (count_nodes(*head) > 3)
				reverse_sort_to_b(head, s2);
			sort_3(head, count_nodes(*head));
			get_in_top(s2, get_max(*s2), 1);
			final_placement(head, s2);
			get_in_top(head, get_min(*head), 0);
		}
	}
}

void	ft_pushswap(int argc, char **argv)
{
	t_struct	*head;
	t_struct	*s2;

	head = NULL;
	s2 = NULL;
	if (fill_list(argc, argv, &head))
		sort_list(&head, &s2);
	else
		write(2, "Error\n", 6);
	free_list(&head);
}

int	main(int argc, char **argv)
{
	ft_pushswap(argc, argv);
}
