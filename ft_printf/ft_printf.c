/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:40 by msintas-          #+#    #+#             */
/*   Updated: 2022/12/01 18:18:01 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_values(int *counter, char c, va_list args)
{
	if (c == 'c')
		ft_putchar_and_count(counter, va_arg(args, int));
	else if (c == 's')
		ft_putstring(counter, va_arg(args, char *));
	else if (c == 'p')
	{
		ft_putstring(counter, "0x");
		ft_putpointer(counter, va_arg(args, void *));
	}
	else if ((c == 'd') || (c == 'i'))
		ft_putnbr(counter, (va_arg(args, int)));
	else if (c == 'u')
		ft_putnbr_unsigned(counter, va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthex_low(counter, va_arg(args, unsigned int));
	else if (c == 'X')
		ft_puthex_up(counter, va_arg(args, unsigned int));
	else if (c == '%')
		ft_putchar_and_count(counter, '%');
}

int	ft_printf(char const *letters_and_placeholders, ...)
{
	va_list	ap;
	int		i;
	int		num_args;
	int		total_printed;

	va_start(ap, letters_and_placeholders);
	i = 0;
	total_printed = 0;
	num_args = ft_strlen_pf(letters_and_placeholders);
	while (i < num_args)
	{
		if (letters_and_placeholders[i] == '%')
		{
			i++;
			ft_printf_values(&total_printed, letters_and_placeholders[i], ap);
		}
		else
			ft_putchar_and_count(&total_printed, letters_and_placeholders[i]);
		i++;
	}
	va_end(ap);
	return (total_printed);
}
