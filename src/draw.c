/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossariass <agossariass@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:25:06 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/05 14:25:08 by agossariass      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_image(t_data *img)
{

	for (int y = 100; y < 200; y++)
		for (int x = 100; x < 200; x++)
			*(unsigned int *)((*img).addr + (y * (*img).line_length + x * ((*img).bits_per_pixel / 8))) = 0xFF0000;


	mlx_put_image_to_window((*img).mlx, (*img).win, (*img).img, 0, 0);

}


void	ft_create_window(t_data *img)
{
	int	ll;
	int	bp;

	(*img).mlx = mlx_init();
	(*img).win = mlx_new_window((*img).mlx, 800, 600, "FDF");
	(*img).img = mlx_new_image((*img).mlx, 800, 600);
	(*img).addr = mlx_get_data_addr(img->img,&bp, &ll, &img->endian);
	(*img).line_length = ll;
	(*img).bits_per_pixel = bp;
}