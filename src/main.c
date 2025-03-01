/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:40:58 by adichou           #+#    #+#             */
/*   Updated: 2025/02/25 20:18:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PUSH_swap.h"

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

void	FT_PUSHSWAP(int argc, char **argv)
{
	t_struct *head = NULL;
	fill_list(argc, argv, &head);
	print_list(&head);
	// rotate(&head);
	// r_rotate(&head);
	swap(&head);
	print_list(&head);
}


int	main(int argc, char **argv)
{
	FT_PUSHSWAP(argc, argv);
}
