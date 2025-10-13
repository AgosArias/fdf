/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:25:06 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/13 09:49:33 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calculate_s(t_point a, t_point b, int *sx, int *sy)
{

	if (a.x < b.x)
		*sx = 1;
	else
		*sx = -1;
	if (a.y < b.y)
		*sy = 1;
	else
		*sy = -1;
}

void	ft_draw_line(t_data *img, t_point a, t_point b)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;

	dx = abs(b.x - a.x);
	dy = -abs(b.y - a.y);
	ft_calculate_s(a, b, &sx, &sy);
	err = dx + dy;
	while (a.x != b.x && a.y != b.y)
	{
		ft_change_colour(img, a.x, a.y, COLOUR);
		if (2 * err >= dy) 
		{
			err += dy;
			a.x += sx;
		}
		if (2 * err <= dx)
		{
			err += dx;
			a.y += sy;
		}
	}
	ft_change_colour(img, a.x, a.y, COLOUR);
}

void	ft_get_dots_and_draw(int x, int y, t_map map, t_data *img)
{
	t_point		p;
	t_point		px;
	t_point		py;

	p = ft_create_point(x, y, map.z[y][x], (*img).camera);
	if (x + 1 < map.width)
	{
		px = ft_create_point(x + 1, y, map.z[y][x + 1], (*img).camera);
		ft_draw_line(img, p, px);
	}
	if (y + 1 < map.height)
	{
		py = ft_create_point(x, y + 1, map.z[y + 1][x], (*img).camera);
		ft_draw_line(img, p, py);
	}
}

void	ft_create_image(t_data *img, t_map map)
{
	int			y;
	int			x;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			ft_get_dots_and_draw(x, y, map, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((*img).mlx, (*img).win, (*img).img, 0, 0);
}
