/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:12:08 by acesar-m          #+#    #+#             */
/*   Updated: 2025/02/11 15:25:34 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

int	is_extension_valid(char *argv)
{
	const char	*extension;

	extension = ".ber";
	if (ft_strcmp(argv[1], extension) == 0)
	{
		ft_printf("Invalid format of map file\n");
		return (0);
	}
	else if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - ft_strlen(extension),extension) == 0)
		return (1);
	else
	{
		ft_printf("file does not end with '.ber'\n");
		return (0);
	}
}

char	*read_file(int file_descriptor)
{
	char		str[101];
	ssize_t		result;
	char		*third;
	static char	*text;

	result = read(file_descriptor, str, 100);
	if (result < 0)
		return (NULL);
	str[result] = '\0';
	while (result != 0)
	{
		third = text;
		text = ft_strjoin(text, str);
		free (third);
		if (text == NULL)
			return (NULL);
		result = read (file_descriptor, str, 100);
		if (result < 0)
		{
			free(text);
			return (NULL);
		}
		str[result] = '\0';
	}
	return (text);
}

char	*open_file(char *filename)
{
	int		file_descriptor;
	char	*text;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_printf("Error\nCould not open file\n");
		return (0);
	}
	else
	{
		text = read_file(file_descriptor);
		if (text == NULL)
			return (NULL);
		else
			return (text);
	}
}

int	is_there_space(char *text)
{
	size_t index;

	index = 0;
	text = ft_strchr(text + index, '1');
	if (text == NULL)
	{
		ft_printf("Error\nMap is not valid\n");
		return (0);
	}
	while (text[index] != '\0')
	{
		if (text[index] == '\n' && text[index + 1] == '\n')
		{
			if (ft_strchr_inverse(text + index, '\n') == NULL)
				return (1);
			else{
				ft_printf("Error\nMap is not valid\n");
				return (0);
			}
		}
		index++;
	}
	return (1);
}

int	file_validation(char **argv, t_maps *mapcontent)
{
	int	result;
	
	if (is_extension_valid(argv) == 0)
		return (0);
	mapcontent->filecontent = open_file(argv[1]);
	if (mapcontent->filecontent == NULL)
	{
		ft_printf("Error\nCould not read file\n");
		return (0);
	}
	result = is_there_space(mapcontent->filecontent);
	if (result == 0)
	{
		free(mapcontent->filecontent);
		return (0);
	}
	else
		return (1);
}
