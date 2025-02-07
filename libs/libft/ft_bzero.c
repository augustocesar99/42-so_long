/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:26:50 by acesar-m          #+#    #+#             */
/*   Updated: 2024/10/29 09:40:27 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t size);

void	ft_bzero(void *s, size_t size)
{
	unsigned char	*ptr;

	ptr = s;
	while (size-- > 0)
	{
		*ptr++ = 0;
	}
}
