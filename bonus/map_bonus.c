/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:55:39 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/09 00:52:09 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_error_free(t_map *map, char *message)
{
	ft_free(map->map);
	free(map);
	ft_error_exit(message);
}

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
			ft_error_free(map, "Error\nMap is not rectangular.\n");
		i++;
	}
	return (1);
}

void	ft_validate_map(t_map *map)
{
	t_char	comp;
	int		i;
	int		j;

	(1) && (i = 0, comp.p = 0, comp.e = 0, comp.c = 0, comp.x = 0);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				comp.p++;
			else if (map->map[i][j] == 'E')
				comp.e++;
			else if (map->map[i][j] == 'C')
				comp.c++;
			else if (map->map[i][j] == 'X')
				comp.x++;
			j++;
		}
		i++;
	}
	if (comp.p != 1 || comp.e != 1 || comp.c < 1 || comp.x < 1)
		ft_error_free(map, "Error\nMissing map components\n");
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
				&& map->map[i][j] != 'E' && map->map[i][j] != 'X'
				&& map->map[i][j] != '\n')
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
