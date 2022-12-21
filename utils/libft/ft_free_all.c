/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:00:12 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/07 11:16:30 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_matrix(char **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
        free(matrix[i]);
    free(matrix);
    matrix = NULL;
    return (matrix);
}

void    ft_free_matrix_void(char **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
        free(matrix[i]);
    free(matrix);
    matrix = NULL;
    return ;
}

// int **free_all_matrix_fdf(int ***numatrix, char ***chmatrix, int size)
// {
//     int i;

//     i = 0;
//     while (i < size)
//         free(*numatrix[i++]);
//     free(*numatrix[i]);
//     free(*numatrix);
//     size = 0;
//     while (*chmatrix[i])
//         size++;
//     while (i < size)
//         free(*chmatrix[i]);
//     free(*chmatrix[i]);
//     return (0);
// }