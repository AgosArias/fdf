/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:19:16 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/15 16:03:01 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_colour(t_data *img, int x, int y, int colour)
{
	int	proy_x;
	int	proy_y;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	proy_x = (int) x * ((*img).bits / 8);
	proy_y = y * (*img).line;
	*(unsigned int *)(img->addr + proy_y + proy_x) = colour;
}

void	ft_clear_img(t_data *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_change_colour(img, x, y, BACKGROUND);
			x++;
		}
		y++;
	}
}

t_point	ft_create_point(int x, int y, int z, t_camera cam)
{
	t_point	p;
	double	ang;
	double	iso_x;
	double	iso_y;
	double	height;

	ang = ANGLE * M_PI / 180.0;
	iso_x = (x - y) * cos(ang);
	iso_y = (x + y) * sin(ang);
	height = z * cam.z_scale;
	p.x = (int)round((iso_x * cam.zoom) + cam.xoff);
	p.y = (int)round(((iso_y - height) * cam.zoom) + cam.yoff);
	return (p);
}
