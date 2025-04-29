/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:04:24 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 23:05:23 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	create_last_node(int data, t_struct **head)
{
	t_struct	*new_node;
	t_struct	*tmp;

	new_node = malloc(sizeof(t_struct));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	create_first_node(int data, t_struct **head)
{
	t_struct	*tmp;

	tmp = malloc(sizeof(t_struct));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->next = *head;
	*head = tmp;
}

void	free_list(t_struct **head)
{
	t_struct		*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free (*head);
		*head = tmp;
	}
}

int	fill_list_str(char *str, t_struct **head)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i ++;
	if (!isstrnum(str))
		return (0);
	while (str[i])
	{
		if (!verify_number(&str[i]))
			return (0);
		create_last_node(ft_atoi(&str[i]), head);
		while (is_char_num(str[i]))
			i ++;
		while (str[i] == ' ')
			i ++;
	}
	if (verif_struct(head))
		return (0);
	return (1);
}
