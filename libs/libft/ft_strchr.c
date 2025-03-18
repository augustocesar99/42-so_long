/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:38:38 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/18 15:38:40 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		count;

	if (s == NULL)
		return (NULL);
	count = -1;
	while (s[++count] != '\0')
		if (s[count] == (char)c)
			return (&s[count]);
	if ((char)c == '\0')
		return (&s[count]);
	return (NULL);
}
