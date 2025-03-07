/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:56:06 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/07 04:37:14 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


void	ft_player(t_game *game, t_map *map)
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
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_exit(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
			{
				game->map->exit_x = j;
				game->map->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_win(t_game *game)
{
	write(1, "\033[1;32mYou won!\033[0m\n", 21);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	ft_put_str_win(t_game *game)
{
	char	*string;
	char	*str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = ft_itoa(game->moves);
	string = ft_strjoin("moves : ", str);
	free(str);
	while (game->map->map[i][j] && j <= 5)
	{
		if (game->map->map[i][j] == '1')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * TILE_SIZE, i * TILE_SIZE);
		}
		j++;
	}
	mlx_string_put(game->mlx, game->win, 12, 6, 16777215, string);
	free(string);
}
void	ft_enemy(t_map *map, t_game *game, int x, int y)
{
	if (game->map->map[y][x] == 'X')
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		ft_free(map->map);
		free(map);
		write(2, "\033[1;31mYou lost!\033[0m\n", 22);
		exit (1);
	}
}
