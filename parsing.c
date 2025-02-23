/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:22:37 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/23 01:33:54 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	int fd;
	char *map;
	char **map_lines;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Could not open map file");
		exit(1);
	}
	map = ft_check_map(fd, "map.ber");
	close(fd);

	ft_validate_map(map);
	ft_check_len(fd, "map.ber");
	map_lines = ft_split(map, '\n');
	if (!map_lines)
	{
		free(map);
		exit(1);
	}
	checkk(fd, "map.ber");
	printf("%s\n", map);
	free(map);
	return (0);
}
