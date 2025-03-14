/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:57:27 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/14 03:34:47 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	map_width(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[0] || !map[0][0] || map[0][0] == '\n')
		return (0);
	while (map[0][i] && map[0][i] != '\n')
	{
		i++;
	}
	return (i);
}

int	count_map(int fd)
{
	char	*str;
	int		len;

	len = 0;
	str = get_next_line(fd);
	while (str)
	{
		len++;
		free(str);
		str = get_next_line(fd);
	}
	if (len == 0)
	{
		close(fd);
		ft_error_exit("Error\nEmpty map.\n");
	}
	return (len);
}

void	close_open_fd(int *fd, char *filename)
{
	close(*fd);
	*fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error\nFile does not exist.\n");
}

void	ft_free_close(int *fd, t_map *map)
{
	close(*fd);
	ft_free(map->map);
	ft_error_exit("Error\nEmpty map.\n");
}

char	**ft_read_map(char *filename, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	**cmap;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_free(map, "Error\nFile does not exist.\n");
	map->height = count_map(fd);
	close_open_fd(&fd, filename);
	cmap = malloc(sizeof(char *) * (map->height + 1));
	if (!cmap)
		return (close(fd), NULL);
	i = 0;
	line = get_next_line(fd);
	while (i < map->height)
	{
		cmap[i++] = line;
		line = get_next_line(fd);
	}
	map->width = map_width(cmap);
	cmap[i] = NULL;
	if (!cmap[0])
		ft_free_close(&fd, map);
	return (close(fd), cmap);
}
