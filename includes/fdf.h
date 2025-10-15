/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:47:42 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/15 16:00:15 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include <mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <math.h>

# ifndef WIN_H
#  define WIN_H 600
# endif

# ifndef WIN_W
#  define WIN_W 800
# endif

# ifndef BACKGROUND
#  define BACKGROUND 0x000000
# endif

# ifndef COLOUR
#  define COLOUR 0xFFFFFF
# endif

# ifndef ZOOM
#  define ZOOM 15
# endif

# ifndef ZSCALE
#  define ZSCALE 0.5
# endif

# ifndef ANGLE
#  define ANGLE 30.0
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_camera
{
	int		xoff;
	int		yoff;
	double	zoom;
	double	z_scale;

}	t_camera;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits;
	int			line;
	int			endian;
	t_camera	camera;
}	t_data;

typedef struct s_map
{
	int		height;
	int		width;
	int		**z;
}	t_map;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

void		ft_error(char *msg);
void		ft_free_matriz(char **matriz);
void		ft_create_window(t_data *img);
void		ft_create_image(t_data *img, t_map map);
t_map		*ft_create_map(char *str);
int			**ft_get_map(int fd, int *wight, int *height);
int			*ft_line_to_array(char *line, int size);
void		ft_add_line(int ***matrix, char *line, int size, int count_words);
void		ft_free_matriz_int(int **matrix);
t_camera	ft_get_camara(void);
void		ft_clear_img(t_data *img);
t_point		ft_create_point(int x, int y, int z, t_camera cam);
void		ft_change_colour(t_data *img, int x, int y, int colour);

#endif