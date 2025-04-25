/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:40:58 by adichou           #+#    #+#             */
/*   Updated: 2025/04/26 01:39:31 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	get_pos(t_struct *head, int data)
{
	int i;
	
	i = 0;
	while (head->next && head->data != data)
	{
		i ++;
		head = head->next;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i ++;
	}
}

int		ft_atoi(const char *nptr)
{
	int	i;
	int	sgn;
	int	res;

	i = 0;
	sgn = 1;
	res = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i ++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sgn = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		i ++;
	}
	return (res * sgn);
}

void	create_last_node(int data, t_struct **head)
{
	t_struct *new_node;
	t_struct *tmp;

	new_node = malloc(sizeof(t_struct));
	if (!new_node)
		return ;
	new_node->data = data;
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

void	create_first_node(int data, t_struct **head)
{
	t_struct *tmp;

	tmp = malloc(sizeof(t_struct));
	if (!tmp)
		return;
	tmp->data = data;
	tmp->next = *head;
	*head = tmp;
}

// remplis la liste avec les elements donnes
void	fill_list(int argc, char **argv, t_struct **head)
{
	int	i;

	i = 0;
	if (argc < 2)
		return;
	while (i < argc - 1)
	{
		create_last_node(ft_atoi(argv[i + 1]), head);
		i ++;
	}
}

// retourne le nombre de noeuds d'une strucure
int		count_nodes(t_struct *head)
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

// affiche une liste pour test
void	print_list(t_struct *head)
{
	printf("\n////////////////////DEBUT////////////////////\n\n");
	while (head)
	{
		printf("valeur %d = %d\n", head->data, get_pos(head, 5));
		head = head->next;
	}
	printf("\n/////////////////////FIN/////////////////////\n\n");
}

// trie une liste de 2 ou 3 elements seulement
void	sort_3(t_struct **head)
{
	if (count_nodes(*head) == 2 && (*head)->data > (*head)->next->data)
		s(head, 0);
	else if (count_nodes(*head) == 3)
	{
		if ((*head)->data > (*head)->next->data && (*head)->data < (*head)->next->next->data)
			s(head, 0);
		else if ((*head)->data > (*head)->next->data && (*head)->next->data > (*head)->next->next->data)
		{
			s(head, 0);
			rr(head, 0);
		}
		else if ((*head)->data > (*head)->next->data && (*head)->data > (*head)->next->next->data)
			r(head, 0);
		else if ((*head)->data < (*head)->next->data && (*head)->next->data > (*head)->next->next->data && (*head)->data < (*head)->next->next->data)
		{
			s(head, 0);
			r(head, 0);
		}
		else if ((*head)->data < (*head)->next->data && (*head)->data > (*head)->next->next->data)
			rr(head, 0);
	}
}

// retourne 0 si la liste n'est pas triee, 1 si elle l'est deja
int		is_sorted(t_struct *head)
{
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);	
}

// retourne le data min contenu dans la structure
int		get_min(t_struct *head)
{
	int 		min;

	min = head->data;
	while (head)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}

// retourne le data max contenu dans la structure
int		get_max(t_struct *head)
{
	int 		max;

	max = head->data;	
	while (head)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);		
}

// retourne 1 si data est le min de head, 2 si data est le max de head, 0 sinon 
int		is_new_max_or_min(int data, t_struct *head)
{
	if (data < get_min(head))
		return (1);
	if (data > get_max(head))
		return (2);
	return (0);
}

// renvoie la plus grande valeur inferieure a data contenue dans head
int		get_higher_min(int	data, t_struct *s2)
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

int		is_under(int len, int indice)
{
	if (indice <= len / 2)
		return (1);
	return (0);	
}

int		is_over(int len, int indice)
{
	if (indice <= len / 2)
		return (0);
	return (1);	
}

int		cmp_int(int index_1, int index_2)
{
	if (index_1 > index_2)
		return (index_1);
	return (index_2);
}

int		cmp_min_int(int index_1, int index_2)
{
	if (index_1 > index_2)
		return (index_2);
	return (index_1);
}

int		under(int size_s1, int size_s2, int	hunter, int target)
{
	if ((is_under(size_s1, hunter) && is_under(size_s2, target)) 
		|| (is_under(size_s1, hunter) && is_over(size_s2, target)
		&& cmp_int(hunter, target) <= cmp_int(size_s1 - hunter, size_s2 - target)
		&& cmp_int(hunter, target) <= size_s2 - target + target)
		|| (is_under(size_s2, target) && is_over(size_s1, hunter)
		&& cmp_int(hunter, target) <= cmp_int(size_s1 - hunter, size_s2 - target)
		&& cmp_int(hunter, target) <= size_s1 - hunter + target))
		return(cmp_int(hunter, target) + 1);
	return (0);
}

int		over(int size_s1, int size_s2, int	hunter, int target)
{
	if ((is_under(size_s1, hunter) && is_under(size_s2, target)) 
		|| (is_under(size_s1, hunter) && is_over(size_s2, target)
		&& cmp_int(hunter, target) > cmp_int(size_s1 - hunter, size_s2 - target)
		&& cmp_int(hunter, target) > size_s2 - target + hunter)
		|| (is_under(size_s2, target) && is_over(size_s1, hunter)
		&& cmp_int(hunter, target) > cmp_int(size_s1 - hunter, size_s2 - target)
		&& cmp_int(hunter, target) > size_s1 - hunter + target))
		return(cmp_int(hunter, target) + 1);
	return (0);
}

int		*get_number_shot(int size_s1, int size_s2, int	hunter, int target)
{
	int		shot[3];

	shot[0] = under(size_s1, size_s2, hunter, target);
	if (!shot[0])
		shot[0] = over(size_s1, size_s2, hunter, target);
	if (!shot[0])
	{
		if (is_under(size_s1, hunter))
			shot[0] = hunter + size_s2 - target + 1;
		else
			shot[0] = target + size_s1 - hunter + 1;
	}
	return (shot);
}

int		find_hunter_and_target(t_struct *s1, t_struct *s2, int *targets)
{
	int		target;
	int		shot_tmp[3];
	int		i;

	i = 0;
	while (s1)
	{
		if (is_new_max_or_min(s1->data, s2) != 0)
			target = get_max(s2);
		else
			target = get_higher_min(s1->data, s2);
		shot_tmp = get_number_shot(count_nodes(s1), count_nodes(s2), i, get_pos(s2, target));
		printf("nombre de coup pour le chiffre %d : %d\n", s1->data, shot_tmp);
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

void	init_target(int *target)
{
	target[0] = 0;
	target[1] = 0;
	target[2] = 0;
}

void	get_both_in_top(t_struct **s1, t_struct **s2, int hunter, int target)
{
	int	i;

	i = 0;
	while (i < cmp_min_int(hunter, target))
	{
		if (hunter > target)
		{
			r(s1, s2, 2);
		}
		else
			r(s1, 2);
	}
	
}

void	push_to_s2(t_struct **s1, t_struct **s2, int *targets)
{
	if (targets[3] == 0 && targets[4] == 0)
		get_both_in_top(s1, s2, targets[0], targets[1]);
	else if (targets[3] == 1 && targets[4] == 1)
		reverse_get_both_in_top(s1, s2, targets[0], targets[1]);
	else
	{
		get_in_top(s1, targets[0]);
		get_in_top(s2, targets[1]);
	}
	p(s1, s2, 1);
}

void	reverse_sort_to_b(t_struct **s1, t_struct **s2)
{
	int 		targets[3];

	init_target(targets);
	find_hunter_and_target(*s1, *s2, targets);
	push_to_s2(s1, s2, targets);
}

void	sort_list(t_struct **head)
{
	t_struct								*s2;
	t_struct								*tmp;
	int										i;

	i = 0;
	s2 = NULL;
	tmp = *head;
	if (!is_sorted(*head))
	{
		if (count_nodes(*head) < 4)
			sort_3(head);
		else
		{
			p(head, &s2, 1);
			p(head, &s2, 1);
			while (count_nodes(*head) > 3)
			{
				reverse_sort_to_b(head, &s2);
			}
			sort_3(head);
			while (i < count_nodes(*head))
				p(&s2, head, 0);
		}	
	}
}

void	FT_PUSHSWAP(int argc, char **argv)
{
	t_struct *head = NULL;
	fill_list(argc, argv, &head);
	//print_list(head);
	sort_list(&head);
	//print_list(head);
}


int	main(int argc, char **argv)
{
	FT_PUSHSWAP(argc, argv);
	
}
