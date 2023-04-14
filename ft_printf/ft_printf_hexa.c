/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:13 by msintas-          #+#    #+#             */
/*   Updated: 2022/09/16 13:44:18 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_low(int *counter, unsigned int n)
{
	unsigned long	nb;

	nb = n;
	if (nb <= 15)
	{
		if (nb <= 9)
			ft_putchar_and_count(counter, nb + '0');
		else
			ft_putchar_and_count(counter, (nb - 10) + 'a');
	}
	else
	{
		ft_puthex_low(counter, nb / 16);
		ft_puthex_low(counter, nb % 16);
	}
}

void	ft_puthex_up(int *counter, unsigned int n)
{
	unsigned long	nb;

	nb = n;
	if (nb <= 15)
	{
		if (nb <= 9)
			ft_putchar_and_count(counter, nb + '0');
		else
			ft_putchar_and_count(counter, (nb - 10) + 'A');
	}
	else
	{
		ft_puthex_up(counter, nb / 16);
		ft_puthex_up(counter, nb % 16);
	}
}

void	ft_puthex_pointer(int *counter, unsigned long nb)
{
	if (nb <= 15)
	{
		if (nb <= 9)
			ft_putchar_and_count(counter, nb + '0');
		else
			ft_putchar_and_count(counter, (nb - 10) + 'a');
	}
	else
	{
		ft_puthex_pointer(counter, nb / 16);
		ft_puthex_pointer(counter, nb % 16);
	}
}

void	ft_putpointer(int *counter, void *ptr)
{
	unsigned long	dir;

	dir = (unsigned long)ptr;
	ft_puthex_pointer(counter, dir);
}
