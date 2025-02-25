/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:11:45 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/24 21:54:24 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangular(char **map)
{
	int	i = 0;
	int	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
		{
			ft_error("Error: Map is not rectangular or Empty line\n");
			exit (1);
		}
		i++;
	}
	return (1);
}

void	ft_validate_map(char **map)
{
	int i = 0;
	int j = 0;
	int p = 0;
	int e = 0;
	int c = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
	{
		ft_error("Error: map should contains only one 'P' and 'E' , and not less than one 'C'\n");
		exit (1);
	}
}

void ft_check_chars(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '\n')
			{
				ft_error("Error: Invalid character in map.\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void ft_check_walls(char **map)
{
	int i = 0;
	int j = 0;
	while(map[i] && map[i][j] == '1')
		j++;
	if ((int)(ft_strlen(map[i]) - 1) != j)
	{
		ft_error("Error: Map is not surrounded by walls.\n");
		exit(1);
	}
	i++;
	j--;
	while(map[i + 1])
	{
		if ( map[i][0] != '1' || map[i][j] != '1')
		{
			ft_error("Error: Map is not surrounded by walls.\n");
			exit(1);
		}
		i++;
	}
	j = 0;
	while(map[i] && map[i][j] == '1')
		j++;
	if ((int)(ft_strlen(map[i]) - 1)!= j)
	{
		ft_error("Error: Map is not surrounded by walls.\n");
		exit(1);
	}
}
