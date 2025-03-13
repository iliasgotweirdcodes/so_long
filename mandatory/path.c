/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:06:45 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 22:50:24 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_dup_map(char **map, int rows)
{
	char	**cmap;
	int		i;
	int		j;

	if (rows <= 0)
		return (NULL);
	i = 0;
	j = 0;
	cmap = malloc(sizeof(char *) * (rows + 1));
	if (!cmap)
		return (NULL);
	while (map[i])
	{
		cmap[j] = ft_strdup(map[i]);
		if (!cmap[j])
			return (free(cmap), NULL);
		j++;
		i++;
	}
	cmap[j] = NULL;
	return (cmap);
}

void	flood_fill(char **cmap, int x, int y, t_map *map)
{
	if (x >= map->width || y >= map->height || x < 0 || y < 0)
		return ;
	if (cmap[y][x] == '1' || cmap[y][x] == 'F')
		return ;
	cmap[y][x] = 'F';
	flood_fill(cmap, x + 1, y, map);
	flood_fill(cmap, x - 1, y, map);
	flood_fill(cmap, x, y + 1, map);
	flood_fill(cmap, x, y - 1, map);
}

void	ft_find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_invalidpath(char **str, t_map *map)
{
	ft_free(map->map);
	ft_free(str);
	ft_error_exit("Error\ninvalid path.\n");
}

void	ft_check_path(t_map *map)
{
	char	**cmap;
	int		k;
	int		i;
	int		j;

	ft_find_player(map);
	i = 0;
	while (map->map[i])
		i++;
	cmap = ft_dup_map(map->map, i);
	flood_fill(cmap, map->player_x, map->player_y, map);
	j = -1;
	while (map->map[++j])
	{
		k = -1;
		while (map->map[j][++k])
		{
			if (map->map[j][k] == 'C' || map->map[j][k] == 'E')
			{
				if (cmap[j][k] != 'F')
					ft_invalidpath(cmap, map);
			}
		}
	}
	ft_free(cmap);
}
