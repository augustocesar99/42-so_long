/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:43:55 by acesar-m          #+#    #+#             */
/*   Updated: 2024/10/29 09:28:28 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_itoa(int n);

static int	get_len(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	num;
	char			*str;

	len = get_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		num = -n;
		str[0] = '-';
	}
	else
		num = n;
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
