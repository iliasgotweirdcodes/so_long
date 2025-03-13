/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:11:27 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/13 01:13:55 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_collectible_exit(t_game *game, t_map *map, int x, int y)
{
	if (map->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			x * TILE_SIZE, y * TILE_SIZE);
		game->map->collectible--;
	}
	if (game->map->collectible == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open,
			map->exit_x * TILE_SIZE, map->exit_y * TILE_SIZE);
		if (map->map[y][x] == 'E' && game->map->collectible == 0)
			ft_win(game);
	}
}
