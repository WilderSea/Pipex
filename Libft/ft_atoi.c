/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:09:34 by msintas-          #+#    #+#             */
/*   Updated: 2022/06/17 18:27:03 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sum;
	int	neg;

	i = 0;
	sum = 0;
	neg = 1;
	while (str[i])
	{
		while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || \
					str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
			i++;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				neg = -1;
		while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		{
			sum = (sum * 10) + (str[i] - '0');
			i++;
		}
		return (sum * neg);
	}
	return (0);
}
