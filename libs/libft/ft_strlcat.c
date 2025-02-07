/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:30:09 by acesar-m          #+#    #+#             */
/*   Updated: 2024/10/23 11:44:56 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	dlen = ft_strlen(dest);
	i = 0;
	while ((src[i] != '\0') && (dlen + 1 < size))
	{
		dest[dlen] = src[i];
		dlen++;
		i++;
	}
	dest[dlen] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
