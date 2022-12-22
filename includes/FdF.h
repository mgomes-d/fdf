/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:53:48 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/22 13:54:12 by mgomes-d         ###   ########.fr       */
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
# include "get_next_line.h"
# include "keycodes.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_img
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

typedef struct s_data
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

void		ft_bresenham_algo(t_matrix a, t_matrix b, t_img *img, t_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
t_matrix	**ft_matrix(int fd, t_data *data);
void		ft_mlxdraw(t_data *data, t_img *img);
void		ft_setparam(t_matrix *a, t_matrix *b, t_data *def);
int			ft_keyimg(int key);
void		ft_action(int keysym, t_data *data);
int			handle_keypress(int keysym, t_data *data);
int			windown_quit(t_data *data);
int			ft_free_fdf(char **charmatrix, t_matrix **dots, char **nmatrix);
t_matrix	**ft_free(char **charmatrix, t_matrix **dots, char **nmatrix);

#endif
