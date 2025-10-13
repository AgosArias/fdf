/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:43:48 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/13 09:50:58 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	ft_get_camara(void)
{
	t_camera	cam;

	cam.xoff = WIN_W / 2;
	cam.yoff = WIN_H / 3;
	cam.zoom = ZOOM;
	cam.z_scale = ZSCALE;
	return (cam);
}

void	ft_create_window(t_data *img)
{
	int			ll;
	int			bp;

	(*img).mlx = mlx_init();
	(*img).win = mlx_new_window((*img).mlx, WIN_W, WIN_H, "FDF");
	(*img).img = mlx_new_image((*img).mlx, WIN_W, WIN_H);
	(*img).addr = mlx_get_data_addr(img->img, &bp, &ll, &img->endian);
	(*img).line = ll;
	(*img).bits = bp;
	(*img).camera = ft_get_camara();
	ft_clear_img(img);
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_map	*map;

	if (argc != 2)
	{
		write(2, "Bad Arguments\n", 14);
		exit (EXIT_FAILURE);
	}
	map = ft_create_map(argv[1]);
	if (!map)
	{
		ft_free_matriz_int(map->z);
		exit(EXIT_FAILURE);
	}
	ft_create_window(&img);
	ft_create_image(&img, *map);
	ft_free_matriz_int(map->z);
	mlx_loop(img.mlx);
	if (map)
		free(map);
	return (0);
}
