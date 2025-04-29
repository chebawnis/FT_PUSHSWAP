/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:40:58 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 19:25:40 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_struct *head, int data)
{
	int	i;

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

int	ft_atoi(const char *nptr)
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

int	verify_number(char *nptr)
{
	int		i;
	int		sgn;
	long	res;

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
	if ((res > 2147483647 && sgn == 1) || (res < -2147483648 && sgn == -1))
		return (0);
	return (1);
}

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

int	verif_struct(t_struct **head)
{
	t_struct	*tmp1;
	t_struct	*tmp2;

	tmp1 = *head;
	tmp2 = *head;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	tmp1 = *head;
	return (0);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i ++;
	}
	return (1);
}

int	is_char_num(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}

int	isstrnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !is_char_num(str[i]))
			return (0);
		i ++;
	}
	return (1);
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

// remplis la liste avec les elements donnes et verifie les doublons etc
int	fill_list(int argc, char **argv, t_struct **head)
{
	int	i;

	i = 0;
	if (argc < 3)
		return (0);
	while (i < argc - 1)
	{
		if (is_num(argv[i + 1]) && verify_number(argv[i + 1]))
			create_last_node(ft_atoi(argv[i + 1]), head);
		else
			return (0);
		i ++;
	}
	if (verif_struct(head))
		return (0);
	return (1);
}

// retourne le nombre de noeuds d'une strucure
int	count_nodes(t_struct *head)
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
// void	print_list(t_struct *head)
// {
// 	printf("\n////////////////////DEBUT////////////////////\n\n");
// 	while (head)
// 	{
// 		printf("valeur pos %d = %d\n", get_pos(head, head->data), head->data);
// 		head = head->next;
// 	}
// 	printf("\n/////////////////////FIN/////////////////////\n\n");
// }

// trie une liste de 2 ou 3 elements seulement
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

// retourne 0 si la liste n'est pas triee, 1 si elle l'est deja
int	is_sorted(t_struct *head)
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
int	get_min(t_struct *head)
{
	int		min;

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
int	get_max(t_struct *head)
{
	int		max;

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
int	is_new_max_or_min(int data, t_struct *head)
{
	if (data < get_min(head))
		return (1);
	if (data > get_max(head))
		return (2);
	return (0);
}

// renvoie la plus grande valeur inferieure a data contenue dans head
int	get_higher_min(int data, t_struct *s2)
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

int	is_under(int len, int indice)
{
	if (indice <= len / 2)
		return (1);
	return (0);
}

int	is_over(int len, int indice)
{
	if (indice > len / 2)
		return (1);
	return (0);
}

int	cmp_int(int index_1, int index_2)
{
	if (index_1 > index_2)
		return (index_1);
	return (index_2);
}

int	cmp_min_int(int index_1, int index_2)
{
	if (index_1 > index_2)
		return (index_2);
	return (index_1);
}

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

void	init_target(int *target)
{
	target[0] = 0;
	target[1] = 0;
	target[2] = 0;
}

void	get_in_top(t_struct **head, int value, int i)
{
	if (is_under(count_nodes(*head), get_pos(*head, value)))
	{
		while (get_pos(*head, value))
			r(head, i);
	}
	else
	{
		while (get_pos(*head, value))
			r_r(head, i);
	}
}

void	a(t_struct **head, int value, int i)
{
	if (is_under(count_nodes(*head), get_pos(*head, value)))
	{
		while (get_pos(*head, value))
			r(head, i);
	}
	else
	{
		while (get_pos(*head, value))
			r_r(head, i);
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
	p(s1, s2, 1);
}

void	reverse_sort_to_b(t_struct **s1, t_struct **s2)
{
	int	targets[3];

	init_target(&targets[0]);
	find_hunter_and_target(*s1, *s2, &targets[0]);
	push_to_s2(s1, s2, targets);
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
