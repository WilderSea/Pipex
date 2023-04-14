/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:17:17 by msintas-          #+#    #+#             */
/*   Updated: 2022/06/17 18:45:24 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_char(int n)
{
	int	numofchar;

	numofchar = 0;
	if (n < 0)
		numofchar++;
	if (n == 0)
		numofchar = 1;
	while (n != 0)
	{
		n /= 10;
		numofchar++;
	}
	return (numofchar);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		numofchar;
	long	nb;

	nb = n;
	numofchar = count_char(n);
	result = malloc((numofchar + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	result[numofchar] = '\0';
	if (nb == 0)
		result[--numofchar] = '0';
	while (nb != 0)
	{
		result[--numofchar] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (result);
}
