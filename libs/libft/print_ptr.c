/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/18 15:39:53 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_hexlong(unsigned long nbr, char *base);

int	print_ptr(unsigned long nbr, char *base)
{
	int	count;

	if (nbr == 0)
		return (print_str("(nil)"));
	count = 0;
	count += print_str("0x");
	count += print_hexlong(nbr, base);
	return (count);
}

static int	print_hexlong(unsigned long nbr, char *base)
{
	int				count;

	count = 0;
	if (nbr > 15)
		count += print_hexlong(nbr / 16, base);
	count += print_char(base[nbr % 16]);
	return (count);
}
