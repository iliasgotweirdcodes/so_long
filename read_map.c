/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:10:50 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/24 15:36:09 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_map(int fd)
{
	char *str;
	int len = 0;
	str = get_next_line(fd);
	while(str)
	{
		len++;
		free(str);
		str = get_next_line(fd);
	}
	return (len);
}
void close_open_fd(int fd , char *filename)
{
	close(fd);
	fd = open(filename, O_RDONLY);
}
char	**ft_read_map(char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;
	int len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error: File does not exist.\n");
		return (NULL);
	}
	len = count_map(fd);
	close_open_fd(fd, filename);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (close(fd), NULL);
	i = 0;
	while ((line = get_next_line(fd)) && i < len)
		map[i++] = line;
	map[i] = NULL;
	close(fd);
	if (i == 0)
	{
		ft_error("Error: Empty map file.\n");
		return (ft_free(map), NULL);
	}
	return (map);
}
