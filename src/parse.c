/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:25:34 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/15 16:02:15 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_line(int ***matrix, char *line, int size, int count_words)
{
	int	**matrix_tmp;
	int	i;
	int	*row;

	if (size < 1)
		return ;
	row = ft_line_to_array(line, count_words);
	matrix_tmp = (int **) malloc (sizeof(int *) * (size + 1));
	if (!matrix_tmp)
		return ;
	i = 0;
	while (*matrix && i < (size) - 1)
	{
		matrix_tmp[i] = (*matrix)[i];
		i++;
	}
	if (*matrix)
		free(*matrix);
	(*matrix) = NULL;
	matrix_tmp[i] = row;
	matrix_tmp[i + 1] = NULL;
	(*matrix) = matrix_tmp;
}

int	*ft_line_to_array(char *line, int size)
{
	char	**array_line;
	int		*array;
	int		i;

	array_line = ft_split(line, ' ');
	array = (int *) malloc (sizeof(int) * (size));
	if (!array)
	{
		ft_free_matriz(array_line);
		return (NULL);
	}
	i = 0;
	while (array_line[i])
	{
		array[i] = ft_atoi(array_line[i]);
		i++;
	}
	ft_free_matriz(array_line);
	return (array);
}

int	**ft_get_map(int fd, int *wight, int *height)
{
	char	*line;
	int		**matrix;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	matrix = NULL;
	*height = 0;
	*wight = ft_count_words(line, ' ');
	while (line)
	{
		(*height)++;
		if (*wight != ft_count_words(line, ' '))
		{
			ft_free_matriz_int(matrix);
			ft_free(line);
			exit(EXIT_FAILURE);
		}
		ft_add_line(&matrix, line, *height, *wight);
		ft_free(line);
		line = get_next_line(fd);
	}
	return (matrix);
}

t_map	*ft_create_map(char *str)
{
	t_map	*map;
	int		fd;

	if (!str)
		return (NULL);
	map = (t_map *) malloc (sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		ft_error("File Error");
	}
	map->z = ft_get_map(fd, &map->width, &map->height);
	if (!map->z)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (map);
}
