/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:47:42 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/10 13:50:35 by aarias-d         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	int		height;
	int		width;
	int		**z;
}	t_map;

typedef struct s_fdf
{
	t_map		map;
	t_data		img;
}	t_fdf;

void	ft_error(char *msg);
void	ft_free_matriz(char **matriz);
int	**ft_create_matriz(char *str);
void	ft_create_window(t_data *img);
void	ft_free_matriz_int(int **matrix);
int	**ft_get_wight_height(int fd, int *wight, int *height);




#endif