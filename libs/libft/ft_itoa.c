/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:38:26 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/18 15:38:27 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convertion(size_t len, int n, char *str);

char	*ft_itoa(int n)
{
	char	*number;
	int		temp;
	size_t	len;

	len = 0;
	temp = n;
	if (n == -2147483648)
	{
		len++;
		temp = -214748364;
	}
	if (temp <= 0)
	{
		len++;
		temp *= -1;
	}
	while (temp > 0)
	{
		len++;
		temp = temp / 10;
	}
	number = malloc((len + 1) * sizeof(char));
	ft_convertion(len - 1, n, number);
	number[len] = '\0';
	return (number);
}

static char	*ft_convertion(size_t len, int n, char *str)
{
	size_t		count;

	count = len;
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n > 9)
	{
		ft_convertion(len - 1, n / 10, str);
		n %= 10;
	}
	str[count] = n + '0';
	return (str);
}
