/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:05:18 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/11 13:22:55 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_free_matriz_int(int **matrix)
{
	int	i;

	if (!matrix || !*matrix)
		return ;
	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_free_matriz(char **matrix)
{
	int	i;

	if (!matrix || !*matrix)
		return ;
	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}
