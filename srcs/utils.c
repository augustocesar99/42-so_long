/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:05:30 by acesar-m          #+#    #+#             */
/*   Updated: 2025/02/11 15:25:42 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	printmap(char **mapfile)
{
	int	line;
	int	colum;

	line = 0;
	while (mapfile[line] != NULL)
	{
		colum = 0;
		while ((mapfile[line])[colum] != '\0')
		{
			printf("%c", (mapfile[line])[colum]);
			colum++;
		}
		printf("\n");
		line++;
	}
}

char	*ft_strchr_inverse(const char *str, int c)
{
	size_t i;

	i = 0;
	if (c > 255)
		c = c % 256;
	while (str[i] != '\0')
	{
		if (str[i] != '\0')
		{
			if (str[i] != (unsigned char)c)
				return ((char *)&str[i]);
			i++;
		}
	}
	return (NULL);
}