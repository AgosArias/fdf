/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:25:34 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/10 21:17:01 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_get_map(int fd, int *wight, int *height)
{
	char	*line;
	char	**aray_line;
	int		*row;
	int		i;
	int		**matrix;
	int		**matrix_tmp;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	matrix = NULL;
	*height = 1;
	*wight = ft_count_words(line, ' ');
	while (line)
	{
		if (*wight != ft_count_words(line, ' '))
		{
			write(2, "Diferent wight\n", 15);
			ft_free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		aray_line = ft_split(line, ' ');
		ft_free(line);
		line = NULL;
		row = (int *) malloc (sizeof(int) * (*wight));
		if (!row)
		{
			ft_free_matriz_int(matrix);
			ft_free_matriz(aray_line);
			exit(EXIT_FAILURE);
			return (NULL);
		}
		i = 0;
		while (aray_line[i])
		{
			row[i] = ft_atoi(aray_line[i]);
			i++;
		}
		ft_free_matriz(aray_line);
		matrix_tmp = (int **) malloc (sizeof(int *) * (*height) + 1);
		if (!matrix_tmp)
		{
			ft_free_matriz_int(matrix);
			exit(EXIT_FAILURE);
			return (NULL);
		}
		i = 0;
		while (matrix && i < (*height) - 1)
		{
			matrix_tmp[i] = matrix[i];
			i++;
		}
		if (matrix)
			free(matrix);
		matrix = NULL;
		matrix_tmp[i] = row;
		matrix_tmp[i + 1] = NULL;
		matrix = matrix_tmp;
		line = get_next_line(fd);
		(*height)++;
	}

	return (matrix);
}


t_map	*ft_create_map(char *str)
{
	t_map	*map;
	int		fd;

	if (!str)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("File Error");
	map->z = ft_get_map(fd, &map->width, &map->height);
	printf("width: %d\n", map->height);
	close(fd);
	return (map);
}
