/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:05:57 by msintas-          #+#    #+#             */
/*   Updated: 2022/06/17 18:14:33 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**pointers_substrings(char *copy, unsigned int len, int words)
{
	char			**array;
	unsigned int	i;
	unsigned int	w;

	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	i = 0;
	w = 0;
	if (copy[i] != '\0')
		array[w++] = ft_strdup(&copy[i]);
	i++;
	while (i < len)
	{
		if (copy[i] != '\0' && copy[i - 1] == '\0')
			array[w++] = ft_strdup(&copy[i]);
		i++;
	}
	array[w] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	int				words;
	char			*copy;
	char			**array;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	copy = ft_strdup(s);
	if (copy == 0)
		return (NULL);
	words = 0;
	i = 0;
	while (i < len)
	{
		if (copy[i] == c)
			copy[i] = '\0';
		else if (i == 0 || copy[i - 1] == '\0')
			words++;
		i++;
	}
	array = pointers_substrings(copy, len, words);
	free(copy);
	return (array);
}
