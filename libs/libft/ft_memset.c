/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:04:44 by acesar-m          #+#    #+#             */
/*   Updated: 2024/10/23 10:00:34 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t size);

void	*ft_memset(void *dest, int value, size_t size)
{
	size_t			i;
	unsigned char	*aux;
	unsigned char	val;

	aux = (unsigned char *)dest;
	val = (unsigned char)value;
	i = 0;
	while (i < size)
	{
		aux[i] = val;
		i++;
	}
	return (aux);
}
