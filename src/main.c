/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:40:58 by adichou           #+#    #+#             */
/*   Updated: 2025/02/23 17:21:55 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_struct
{
	int										data;
	int										index;
	struct s_struct							*next;
} t_struct;

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


void	print_list(t_struct **head)
{
	t_struct	*tmp;

	tmp = *head;
	while (tmp)
	{
		printf("valeur %d = %d\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
}

void rotate(t_struct **head)
{
	t_struct								 *first;
	t_struct 								*tmp;
	int 									i;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	tmp = *head;
	i = 0;
	*head = first->next;
	first->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void r_rotate(t_struct **head)
{
	t_struct *prev;
	t_struct *tmp;
	int i;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	prev = NULL;
	tmp = *head;
	i = 0;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *head;
	*head = tmp;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_struct *node1 = NULL;
	fill_list(argc, argv, &node1);
	print_list(&node1);
	r_rotate(&node1);
	print_list(&node1);
}
