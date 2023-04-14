/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:31 by msintas-          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:33 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pf(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_and_count(int *counter, char c)
{
	write(1, &c, 1);
	*counter = *counter + 1;
}

void	ft_putstring(int *counter, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putchar_and_count(counter, '(');
		ft_putchar_and_count(counter, 'n');
		ft_putchar_and_count(counter, 'u');
		ft_putchar_and_count(counter, 'l');
		ft_putchar_and_count(counter, 'l');
		ft_putchar_and_count(counter, ')');
		return ;
	}
	while (str[i])
	{
		ft_putchar_and_count(counter, str[i]);
		i++;
	}
}

void	ft_putnbr(int *counter, int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_and_count(counter, '-');
		nb *= -1;
	}
	if (nb <= 9)
		ft_putchar_and_count(counter, nb + '0');
	else
	{
		ft_putnbr(counter, nb / 10);
		ft_putnbr(counter, nb % 10);
	}
}

void	ft_putnbr_unsigned(int *counter, unsigned int nb)
{
	if (nb <= 9)
		ft_putchar_and_count(counter, nb + '0');
	else
	{
		ft_putnbr(counter, nb / 10);
		ft_putnbr(counter, nb % 10);
	}
}
