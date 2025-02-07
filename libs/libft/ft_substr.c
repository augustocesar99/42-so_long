/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:35:19 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 11:24:56 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_size;

	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	if (start > str_size)
	{
		len = 1;
		start = 0;
	}
	else if (start + len > str_size)
		len = str_size - start + 1;
	else
		len = len +1;
	result = malloc(len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len);
	return (result);
}
