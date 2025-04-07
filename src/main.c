/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:40:58 by adichou           #+#    #+#             */
/*   Updated: 2025/03/08 22:44:36 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_last_node(int data, int index, t_struct **head)
{
	t_struct *new_node;
	t_struct *tmp;

	new_node = malloc(sizeof(t_struct));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->index = index;
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	create_first_node(int data, int index, t_struct **head)
{
	t_struct *tmp;

	tmp = malloc(sizeof(t_struct));
	if (!tmp)
		return;
	tmp->data = data;
	tmp->index = index;
	tmp->next = *head;
	*head = tmp;
}


void	fill_list(int argc, char **argv, t_struct **head)
{
	int	i;

	i = 0;
	if (argc < 2)
		return;
	while (i < argc - 1)
	{
		create_last_node(atoi(argv[i + 1]), i, head);
		i ++;
	}
}

int	count_nodes(t_struct **head)
{
	int										i;
	t_struct								*tmp;

	if (!head || !(*head))
		return (0);
	i = 0;
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}


int	node_on_top(t_struct **s)
{
	t_struct								*tmp;
	int										size;

	tmp = *s;
	while (tmp)
		tmp = tmp->next;		
	size = tmp->index;
	tmp = *s;
	if (tmp->index < size / 2)
		return (tmp->index);
	else
		return (size - tmp->index);
}

t_struct	*find_target(int	n, t_struct **s2)
{
	t_struct								*tmp;
	int										index_target;
	int										value_target;

	tmp = *s2;
	value_target = 0;
	index_target = 0;
	while (tmp)
	{
		if (tmp->data < n && tmp->data > value_target)
		{
			index_target = tmp->index;
			value_target = tmp->data;
		}
		tmp = tmp->next;
	}
	tmp = *s2;
	while (tmp->index != index_target)
		tmp = tmp->next;
	return (tmp);
}

int		find_target_index(int	n, t_struct **s2)
{
	t_struct								*tmp;
	int										index_target;
	int										value_target;

	tmp = *s2;
	value_target = 0;
	index_target = 0;
	while (tmp)
	{
		if (tmp->data < n && tmp->data > value_target)
		{
			index_target = tmp->index;
			value_target = tmp->data;
		}
		tmp = tmp->next;
	}
	tmp = *s2;
	while (tmp->index != index_target)
		tmp = tmp->next;
	return (tmp);
}

int	get_nc(t_struct	**s1, t_struct **s2)
{
	t_struct								*tmp;

	tmp = find_target((*s1)->data, s2);
	return (node_on_top(s1) + node_on_top(&tmp) + 1);
}

void	print_list(t_struct **head)
{
	t_struct	*tmp;

	tmp = *head;
	printf("\n////////////////////DEBUT////////////////////\n\n");
	while (tmp)
	{
		printf("valeur %d = %d\n", tmp->index + 1, tmp->data);
		tmp = tmp->next;
	}
	printf("\n/////////////////////FIN/////////////////////\n\n");
}

int		get_node_index(t_struct **s1, t_struct **s2)
{
	t_struct								*tmp;
	int										nc;
	int										res;

	tmp = *s1;
	nc = get_nc(tmp, s2);
	res = 0;
	while (get_nc(tmp, s2))
	{
		if (get_nc(tmp, s2) > nc)
		{
			nc = get_nc(tmp, s2);
			res = tmp->index;
		}
		tmp = tmp->next;
	}
	return (res);
}

void	get_in_top(t_struct **head, int best_index)
{
	int										i;
	int										total;

	i = best_index;
	total = count_nodes(head);
	if (best_index > total / 2)
	{
		while (i < total)
		{
			r_rotate(head);
			i ++;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate(head);
			i --;
		}
	}
}

void	firstpart(t_struct **s1, t_struct **s2, int best_index)
{
	get_in_top(s1, best_index);
	get_in_top(s2, find_target_index((*s1)->data, s2));
	push(s1, s2);
}

void	sort_3(t_struct **head)
{
	int	a;
	int	b;
	int	c;

	if (!head || !*head || !((*head)->next) || !((*head)->next->next))
		return;
	a = (*head)->data;
	b = (*head)->next->data;
	c = (*head)->next->next->data;
	
	if (a < b && b < c)
		return;
	else if (a > b && a < c)
		swap(head);
	else if (a > b && b > c)
	{
		swap(head);
		r_rotate(head);
	}
	else if (a > b && a > c)
		rotate(head);
	else if (a < b && b > c && a < c)
	{
		swap(head);
		rotate(head);
	}
	else if (a < b && a > c)
		r_rotate(head);
}

void	sort_list(t_struct **head)
{
	t_struct								*s2;
	t_struct								*tmp;
	int										i;

	i = 0;
	tmp = *head;
	create_first_node(tmp->data, 0, &s2);
	if (tmp->next)
		create_last_node(tmp->next->data, 1, &s2);
	while (count_nodes(head) >= 3)
	{
		firstpart(head, s2, get_node_index(head, s2));
	}
	sort_3(head);
}

void	FT_PUSHSWAP(int argc, char **argv)
{
	t_struct *head = NULL;
	fill_list(argc, argv, &head);
	print_list(&head);
	// rotate(&head);
	// r_rotate(&head);
	swap(&head);
	print_list(&head);
	sort_list(&head);
	print_list(&head);
}


int	main(int argc, char **argv)
{
	FT_PUSHSWAP(argc, argv);
}
