/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:43:48 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/10 14:16:00 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	main(int argc, char **argv)
{
	int	**matriz;
	t_data	img;
	int		i;

	if (argc != 2)
		ft_error("Bad Arguments");
	matriz = ft_create_matriz(argv[1]);
	i = 0;
	if(matriz)
		printf("ACA\n");

	while (i < 19)
	{
		printf("%d\n",matriz[3][i]);
		i++;
	}

	ft_free_matriz_int(matriz);
	//ft_create_window(&img);
	//ft_create_image(&img);
	//mlx_loop(img.mlx);


	return (0);
}
