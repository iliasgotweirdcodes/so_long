/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:10:50 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/25 23:59:22 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width(char **map)
{
	int i;

	i = 0;
	if (!map || !map[0] || !map[0][0] || map[0][0] == '\n')
		return (0);
	while (map[0][i] && map[0][i] != '\n')
	{
		i++;
	}
	return (i);
}

int count_map(int fd)
{
	char *str;
	int len;

	len = 0;
	str = get_next_line(fd);
	while(str)
	{
		len++;
		free(str);
		str = get_next_line(fd);
	}
	// free(str);
	return (len);
}
void close_open_fd(int fd , char *filename)
{
	close(fd);
	fd = open(filename, O_RDONLY);
}
char	**ft_read_map(char *filename, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	**cmap;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error: File does not exist.\n");
		return (NULL);
	}
	map->height = count_map(fd);
	if (map->height == 0)
	{
		ft_error("Error: Empty map.\n");
		return (close(fd), NULL);
	}
	close_open_fd(fd, filename);
	cmap = malloc(sizeof(char *) * (map->height + 1));
	if (!cmap)
		return (close(fd), free(map), NULL);
	i = 0;
	while ((line = get_next_line(fd)) && i < map->height)
	{
		cmap[i++] = line;
	}
	map->width = map_width(cmap);
	cmap[i] = NULL;
	if (i == 0)
	{
		ft_error("Error: Empty map.\n");
		return (close(fd), NULL);
	}
	close(fd);
	return (cmap);
}
