/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:40:58 by adichou           #+#    #+#             */
/*   Updated: 2025/02/23 15:13:54 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

typedef struct s_struct
{
	int										data;
	int										index;
	t_struct								*next;
} t_struct;

void	create_last_node(int data, int index, t_struct **head)
{
	t_struct *tmp;

	tmp = *head;
	tmp = malloc(sizeof(t_struct));\
	if (!tmp)
		return ;
	while (tmp)
		tmp = tmp->next;
	tmp->data = data;
	tmp->index = index;
	tmp->next = NULL;
}

void	create_first_node(int data, int index, t_struct **head)
{
	t_struct *tmp;

	tmp = malloc(sizeof(t_struct));
	tmp->data = data;
	tmp->index = index;
	tmp->next = *head;
	*head = tmp;
}


void	fill_list(int argc, char **argv, t_struct **head)
{
	t_struct	*tmp;

	tmp = *head;
	if (argc < 2)
		return;
	
	

	int i = 0;
	while (i < argc)
	{
		tmp = malloc(sizeof(t_struct));
		tmp->data = atoi(argv[i + 1]);
		tmp->index = i;
		tmp->next = NULL;
		i ++;
		if (i < argc)
			tmp->next = tmp;
	}
	
}

int	main(int argc, char **argv)
{
	t_struct *node1;
	fill_list(argc, argv, &node1);
}
