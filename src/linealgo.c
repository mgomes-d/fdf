/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linealgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:04:28 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/21 11:30:13 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
static void	ft_fist_algo(t_img *img, t_bresen line, int ex, int ey)
{
	int	dx;
	int	dy;
	int	fx;

	fx = ex;
	dx = 2 * ex;
	dy = 2 * ey;
	while (line.i <= fx)
	{
		img_pix_put(img, line.x, line.y, WHITE_PIXEL);
		line.i++;
		line.x += line.xincr;
		ex -= dy;
		if (ex < 0)
		{
			line.y += line.yincr;
			ex += dx;
		}
	}
}

static void	ft_second_algo(t_img *img, t_bresen line, int ex, int ey)
{
	int	dx;
	int	dy;
	int	fy;

	fy = ey;
	dx = 2 * ex;
	dy = 2 * ey;
	while (line.i <= fy)
	{
		img_pix_put(img, line.x, line.y, WHITE_PIXEL);
		line.i++;
		line.y += line.yincr;
		ey -= dx;
		if (ey < 0)
		{
			line.x += line.xincr;
			ey += dy;
		}
	}
}

static t_bresen	ft_structbresen(t_matrix a)
{
	t_bresen	line;

	line.x = a.x;
	line.y = a.y;
	line.xincr = 1;
	line.yincr = 1;
	line.i = 0;
	return (line);
}

void	ft_bresenham_algo(t_matrix a, t_matrix b, t_img *img, t_data *data)
{
	int			fx;
	int			fy;
	t_bresen	line;

	ft_setparam(&a, &b, data);
	line = ft_structbresen(a);
	fx = fabs(b.x - a.x);
	fy = fabs(b.y - a.y);
	if (a.x > b.x)
		line.xincr--;
	if (a.y > b.y)
		line.yincr--;
	if (fx > fy)
		ft_fist_algo(img, line, fx, fy);
	if (fx < fy)
		ft_second_algo(img, line, fx, fy);
	return ;
}
*/


double	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	ft_bresenham_algo(t_matrix a, t_matrix b, t_img *img, t_data *data)
{
	double	step_x;
	double	step_y;
	double	max;
	int		color;

	ft_setparam(&a, &b, data);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		img_pix_put(img, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > WINDOW_WIDTH || a.y > WINDOW_HEIGHT || a.y < 0 || a.x < 0)
			break ;
	}
}
