/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:19:48 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/22 12:11:46 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>

static int	ft_read_file(int fd, char ***charmatrix)
{
	char	*line;
	char	*text;
	int		i;

	i = 0;
	text = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		text = ft_strjoin(text, line);
		i++;
		free(line);
	}
	*charmatrix = ft_split(text, '\n');
	close(fd);
	free(text);
	return (i);
}

static int	ft_whilemlx(char **charmatrix, t_matrix **dots, int i)
{
	char	**numatrix;
	int		j;

	j = 0;
	numatrix = ft_split(charmatrix[i], ' ');
	while (numatrix[j])
		j++;
	dots[i] = (t_matrix *)malloc(sizeof(t_matrix) * (j));
	if (!dots[i])
		return (ft_free_fdf(charmatrix, dots, numatrix));
	j = 0;
	while (numatrix[j])
	{
		dots[i][j].z = ft_atoi(numatrix[j]);
		dots[i][j].x = j;
		dots[i][j].y = i;
		free(numatrix[j++]);
	}
	free(numatrix);
	return (j);
}

static t_matrix	**ft_utilmtx(char **charmatrix, t_matrix **dots, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (charmatrix[i])
	{
		j = ft_whilemlx(charmatrix, dots, i);
		data->row[i] = j;
		free(charmatrix[i++]);
	}
	dots[i] = NULL;
	free(charmatrix);
	data->line = i;
	return (dots);
}

t_matrix	**ft_matrix(int fd, t_data *data)
{
	char		**charmatrix;
	t_matrix	**matrix_dots;
	int			size;

	size = ft_read_file(fd, &charmatrix);
	matrix_dots = (t_matrix **)malloc(sizeof(t_matrix *) * (size + 1));
	if (!matrix_dots)
		return (ft_free(charmatrix, 0, 0));
	data->row = ft_calloc(sizeof(int *), size);
	if (!data->row)
		return (ft_free(0, matrix_dots, 0));
	matrix_dots = ft_utilmtx(charmatrix, matrix_dots, data);
	return (matrix_dots);
}
