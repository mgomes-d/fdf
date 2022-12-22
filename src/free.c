/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:07:56 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/22 12:13:11 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_free_fdf(char **charmatrix, t_matrix **dots, char **nmatrix)
{
	int	i;

	if (charmatrix)
	{
		i = 0;
		while (charmatrix[i])
			free(charmatrix[i++]);
		free(charmatrix);
	}
	if (nmatrix)
	{
		i = 0;
		while (nmatrix[i])
			free(nmatrix[i++]);
		free(nmatrix);
	}
	if (dots)
	{
		i = 0;
		while (dots[i])
			free(dots[i++]);
		free(dots);
	}
	return (0);
}

t_matrix	**ft_free(char **charmatrix, t_matrix **dots, char **nmatrix)
{
	int	i;

	if (charmatrix)
	{
		i = 0;
		while (charmatrix[i])
			free(charmatrix[i++]);
		free(charmatrix);
	}
	if (nmatrix)
	{
		i = 0;
		while (nmatrix[i])
			free(nmatrix[i++]);
		free(nmatrix);
	}
	if (dots)
	{
		i = 0;
		while (dots[i])
			free(dots[i++]);
		free(dots);
	}
	return (0);
}
