/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:04 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/18 15:39:06 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_lines(int fd, char *str);
static char	*ft_current_line(char *str, char *line);
static char	*ft_get_rest(char *str);

char	*get_next_line(int fd)
{
	static char	*next_lines[4096];
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_lines[fd] = ft_get_lines(fd, next_lines[fd]);
	if (next_lines[fd] == NULL)
		return (NULL);
	current_line = NULL;
	current_line = ft_current_line(next_lines[fd], current_line);
	next_lines[fd] = ft_get_rest(next_lines[fd]);
	return (current_line);
}

static char	*ft_get_lines(int fd, char *str)
{
	char	*temp;
	int		temp_len;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp_len = 1;
	while (ft_strchr(str, '\n') == NULL && temp_len != 0)
	{
		temp_len = read(fd, temp, BUFFER_SIZE);
		if (temp_len < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[temp_len] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

static char	*ft_current_line(char *str, char *line)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
		return (NULL);
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\n')
		line = malloc((count + 2) * sizeof(char));
	else if (str[count] == '\0')
		line = malloc((count + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	count = -1;
	while (str[++count] != '\n' && str[count] != '\0')
		line[count] = str[count];
	if (str[count] == '\n')
		line[count++] = '\n';
	line[count] = '\0';
	return (line);
}

static char	*ft_get_rest(char *str)
{
	size_t	count;
	size_t	str_len;
	char	*rest;
	size_t	rest_count;

	count = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	if (str[count] == '\0')
	{
		free (str);
		return (NULL);
	}
	str_len = ft_strlen(str);
	rest = malloc((str_len - count) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	count++;
	rest_count = 0;
	while (str[count] != '\0')
		rest[rest_count++] = str[count++];
	rest[rest_count] = '\0';
	free(str);
	return (rest);
}
