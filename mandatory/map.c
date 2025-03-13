/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:11:45 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/13 00:55:44 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_rectangular(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	if (!map->map || !map->map[0])
		return (0);
	len = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != len)
			ft_error_free(map, "Error\nMap is not rectangular or empty line\n");
		i++;
	}
	return (1);
}

void	ft_validate_map(t_map *map)
{
	int	i;
	int	j;
	int	p ;
	int	e;
	int	c;

	(1) && (i = 0, p = 0, e = 0, c = 0);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				p++;
			else if (map->map[i][j] == 'E')
				e++;
			else if (map->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		ft_error_free(map, "Error\nError in map components\n");
}

void	ft_check_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'P'
				&& map->map[i][j] != 'E' && map->map[i][j] != '\n')
				ft_error_free(map, "Error\nInvalid character in map.\n");
			j++;
		}
		i++;
	}
}

void	ft_check_walls(t_map *map)
{
	int	i;
	int	j;

	(1) && (i = 0, j = 0);
	while (map->map[i] && map->map[i][j] == '1')
		j++;
	if ((int)(ft_strlen(map->map[i]) - 1) != j)
		ft_error_free(map, "Error\nMap is not surrounded by walls.\n");
	i++;
	j--;
	while (map->map[i + 1])
	{
		if (map->map[i][0] != '1' || map->map[i][j] != '1')
			ft_error_free(map, "Error\nMap is not surrounded by walls.\n");
		i++;
	}
	j = 0;
	while (map->map[i] && map->map[i][j] == '1')
		j++;
	if ((int)(ft_strlen(map->map[i]) - 1) != j)
		ft_error_free(map, "Error\nMap is not surrounded by walls.\n");
}
