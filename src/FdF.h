/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:53:48 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/20 13:42:18 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 2560
# define WINDOW_HEIGHT 1395

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "../utils/getnextline/get_next_line.h"
# include "keycodes.h"
# include "../utils/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h> //f
# define MAX(A, B) (A > B ? A : B)


typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_matrix
{
	double	x;
	double	y;
	double	z;
}	t_matrix;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fd;
	t_matrix	**matrix;
	int			line;
	int			*row;
	int			x;
	int			y;
	int			scale;
	int			z_scale;
	double		angle;
	int			distance_x;
	int			distance_y;
	int			isometric;
	t_img		img;
}	t_data;



typedef struct	s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct	s_bresen
{
	int	x;
	int y;
	int	xincr;
	int	yincr;
	int	i;
}	t_bresen;

typedef struct	s_map
{
	int **matrix;
	int lines;
	int *row;
}	t_map;

void	ft_bresenham_algo(t_matrix a, t_matrix b, t_img *img, t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
t_matrix	**ft_matrix(int fd, t_data *data);
void	ft_mlxdraw(t_data *data, t_img *img);
void	ft_setparam(t_matrix *a, t_matrix *b, t_data *def);

#endif
