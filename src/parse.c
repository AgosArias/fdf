/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossariass <agossariass@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:25:34 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/04 14:11:09 by agossariass      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_create_matriz(char *str)
{
	int		fd;
	char	*line;

	if (!str)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("File Error");
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
	}
	return (

	)
}
void	ft_free_matriz(char **matriz)
{
	int	i;

	if (!matriz && !*matriz)
		return ;
	i = 0;
	while (matriz[i])
		free(matriz[i++]);
	free(matriz);
	matriz = NULL;
}