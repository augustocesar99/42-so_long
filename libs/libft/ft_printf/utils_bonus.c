/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:53:35 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/01/19 21:49:46 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	write_hex(unsigned long long n, int *bytes, char *hex_values)
{
	if (n >= 16)
		write_hex(n / 16, bytes, hex_values);
	*bytes += ft_putchar(hex_values[n % 16]);
}

void	write_nbr(long long n, int *bytes)
{
	char	c;

	if (n > 9)
		write_nbr(n / 10, bytes);
	c = (n % 10) + '0';
	*bytes += ft_putchar(c);
}

size_t	ft_stringlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
