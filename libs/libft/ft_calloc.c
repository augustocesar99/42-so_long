/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:28:00 by acesar-m          #+#    #+#             */
/*   Updated: 2024/10/29 10:17:09 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size);

void	*ft_calloc(size_t num, size_t size)
{
	void	*rtn;

	if (num != 0 && size > (size_t)-1 / num)
		return (NULL);
	rtn = malloc(num * size);
	if (rtn == NULL)
		return (NULL);
	ft_memset(rtn, 0, num * size);
	return (rtn);
}
