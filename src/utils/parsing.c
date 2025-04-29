/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:19:23 by adichou           #+#    #+#             */
/*   Updated: 2025/04/30 00:09:23 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	verify_number(char *nptr)
{
	int		i;
	int		sgn;
	long	res;

	i = 0;
	sgn = 1;
	res = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sgn = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	res *= sgn;
	if (res > 2147483647L || res < -2147483648L)
		return (0);
	return (1);
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

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	parse_tab(char **tab, t_struct **head, int size_tab)
{
	int	i;

	i = 0;
	while (i < size_tab)
	{
		if (is_num(tab[i]) && verify_number(tab[i]))
			create_last_node(ft_atoi(tab[i]), head);
		else
			return (0);
		i++;
	}
	if (verif_struct(head))
		return (0);
	return (1);
	ft_free_tab(tab);
}

// remplis la liste avec les elements donnes et verifie les doublons etc
int	fill_list(int argc, char **argv, t_struct **head)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	if (argc == 2 && isstrnum(argv[1]))
	{
		tab = ft_split(argv[1], ' ');
		if (!parse_tab(tab, head, countwords(argv[1], ' ')))
			return (0);
		return (1);
	}
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
