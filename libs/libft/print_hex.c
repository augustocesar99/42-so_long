/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/18 15:39:48 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned int nbr, char *str, int index, int hash_check)
{
	int	count;

	count = 0;
	if (nbr != 0 && str[index - 1] == '#' && hash_check == 1)
	{
		if (str[index] == 'x')
			count += print_str("0x");
		else
			count += print_str("0X");
	}
	hash_check = 0;
	if (str[index] == 'X')
	{
		if (nbr > 15)
			count += print_hex(nbr / 16, str, index, hash_check);
		count += print_char(UPPER_HEX[nbr % 16]);
	}
	else
	{
		if (nbr > 15)
			count += print_hex(nbr / 16, str, index, hash_check);
		count += print_char(LOWER_HEX[nbr % 16]);
	}
	return (count);
}
