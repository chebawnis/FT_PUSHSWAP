/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:01:00 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 22:59:49 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && !is_char_num(str[i]))
			return (0);
		i ++;
	}
	return (1);
}
