/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:37:01 by msintas-          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:37 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(char const *letters_and_placeholders, ...);
size_t	ft_strlen_pf(const char *s);
void	ft_putstring(int *counter, char *str);
void	ft_putpointer(int *counter, void *ptr);
void	ft_puthex_pointer(int *counter, unsigned long n);
void	ft_putnbr(int *counter, int n);
void	ft_putnbr_unsigned(int *counter, unsigned int nb);
void	ft_puthex_low(int *counter, unsigned int n);
void	ft_puthex_up(int *counter, unsigned int n);
void	ft_putchar_and_count(int *total_printed, char c);

#endif
