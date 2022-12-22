/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:40:04 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/05 12:28:43 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_put_in_line(char *src)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] && src[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static char	*ft_cpy_after_nl(char *str)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (ft_free_all(&str));
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	j = 0;
	if (!str[i])
		return (ft_free_all(&str));
	while (str[i + j])
		j++;
	dest = malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (ft_free_all(&str));
	j = 0;
	while (++j && str[i + j - 1])
		dest[j - 1] = str[i + j - 1];
	dest[j - 1] = '\0';
	free(str);
	return (dest);
}

static char	*ft_forlineread_while(int fd, char *str)
{
	char		buffer[BUFFER_SIZE + 1];
	int			read_ret;

	if (!str)
	{
		str = malloc(sizeof(char) + 1);
		if (!str)
			return (ft_free_all(&str));
		str[0] = '\0';
	}
	read_ret = 1;
	while (ft_not_nl_static(str) && read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
			return (ft_free_all(&str));
		buffer[read_ret] = '\0';
		str = ft_strjoingnl(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	str = ft_forlineread_while(fd, str);
	line = ft_put_in_line(str);
	if (!line)
		return (ft_free_all(&str));
	str = ft_cpy_after_nl(str);
	return (line);
}
