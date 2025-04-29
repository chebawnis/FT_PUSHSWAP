/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:23:36 by adichou           #+#    #+#             */
/*   Updated: 2025/04/29 22:39:50 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count ++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*alloc_word(char const *s, int *i, char c)
{
	int		start;
	int		len;
	char	*word;
	int		j;

	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

static void	freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;
	int		i;
	int		j;

	count = countwords(s, c);
	tab = malloc((count + 1) * sizeof(char *));
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			tab[j++] = alloc_word(s, &i, c);
		if (j >= 1 && !tab[j - 1])
			return (freetab(tab), NULL);
	}
	tab[j] = NULL;
	return (tab);
}
