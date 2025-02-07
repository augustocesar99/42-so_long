/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:29:49 by acesar-m          #+#    #+#             */
/*   Updated: 2024/10/24 10:21:53 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		n = 0;
		while (big[i + n] == little[n] && (i + n) < len)
		{
			if (big[i + n] == '\0' && little[n] == '\0')
				return ((char *)&big[i]);
			n++;
		}
		if (little[n] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
