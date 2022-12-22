/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:57:26 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/11/06 14:49:59 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_all(char **str1)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	return (0);
}

int	ft_not_nl_static(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		free(str);
		return (0);
	}
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoingnl(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*join;

	size = ft_strlen(str1) + ft_strlen(str2);
	if (!size)
		return (ft_free_all(&str1));
	join = malloc(sizeof(char) * (size + 1));
	if (!join)
		return (ft_free_all(&str1));
	i = 0;
	j = 0;
	if (str1)
	{
		while (str1[i] && j < size)
			join[j++] = str1[i++];
	}
	i = 0;
	while (str2[i] && j < size)
		join[j++] = str2[i++];
	join[j] = '\0';
	free(str1);
	return (join);
}
