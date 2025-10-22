/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:43:48 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/21 13:39:15 by aarias-d         ###   ########.fr       */
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

int	ft_destroy_window(void *param)
{
	t_data	*img;

	img = (t_data *)param;
	if (!img || !img->mlx)
		exit(EXIT_SUCCESS);
	if (img->img)
	{
		mlx_destroy_image(img->mlx, img->img);
		img->img = NULL;
	}
	if (img->win)
	{
		mlx_destroy_window(img->mlx, img->win);
		img->win = NULL;
	}
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	img->mlx = NULL;
	exit(EXIT_SUCCESS);
}

int	ft_close(int keycode, void *param)
{
	if (keycode != 65307 && keycode != 120)
		return (0);
	ft_destroy_window(param);
	exit(EXIT_SUCCESS);
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
	if (map)
		free(map);
	mlx_hook(img.win, 2, 1L << 0, ft_close, &img);
	mlx_hook(img.win, 17, 0L, ft_destroy_window, &img);
	mlx_loop(img.mlx);
	return (0);
}
