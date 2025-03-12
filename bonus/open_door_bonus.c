/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:11:27 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 16:07:47 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_load_door(t_game *game)
{
	game->img_demension = 32;
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/opened_exit.xpm",
			&game->img_demension, &game->img_demension);
	if (!game->img_exit_open)
	{
		destroy_images(game);
		ft_free(game->map->map);
		free(game->map);
		ft_error_exit("Error\nFailed to load textures\n");
	}
}

void	ft_collectible_exit(t_game *game, t_map *map, int x, int y)
{
	ft_load_door(game);
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
