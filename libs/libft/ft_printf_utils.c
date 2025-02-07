/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:52:48 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/13 14:26:51 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str_pf(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_base_pf(long long n, char *base, int div)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0 && div == 10)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= div)
		count += print_base_pf(n / div, base, div);
	c = base[n % div];
	count += print_char_pf(c);
	return (count);
}

int	print_point_pf(unsigned long p)
{
	int		i;
	int		count;
	char	*base;
	char	str[17];

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	if (!p || p == 0)
		return (print_str_pf("(nil)"));
	count = print_str_pf("0x");
	while (p > 0)
	{
		str[i] = base[p % 16];
		p /= 16;
		i++;
	}
	count += i;
	i--;
	while (i >= 0)
		write (1, &str[i--], 1);
	return (count);
}
