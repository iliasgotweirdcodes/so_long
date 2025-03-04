/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:20:23 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/04 00:26:07 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_start_game(t_game *game, char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error: File does not exist.\n");
    if (!game->mlx)
    {
		close (fd);
		ft_error_exit("Error: Failed to initialize MLX\n");
    }
    game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE, game->map->height * TILE_SIZE, "So Long");
    if (!game->win)
	{
		close (fd);
		ft_error_exit("Error: Failed to create window\n");
	}
	close (fd);
}

void ft_load_img(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->map->width, &game->map->height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->map->width, &game->map->height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->map->width, &game->map->height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/coins.xpm", &game->map->width, &game->map->height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/closed_exit.xpm", &game->map->width, &game->map->height);
	if (!game->img_player || !game->img_wall || !game->img_floor || !game->img_collectible || !game->img_exit)
		ft_error_exit("Error: Failed to load textures\n");
}
void ft_decide_comp(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
		game->map->collectible++;
	}
	else if (game->map->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
}
void ft_draw_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	ft_load_img(game);
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			ft_decide_comp(game, x, y);
			x++;
		}
		y++;
	}
}

// void ft_win(t_game *game)
// {
// 	if (game->map->map[game->map->player_y][game->map->player_x] == 'E')
// 	{
// 		if (game->map.collectible == 0)
// 			ft_error_exit("Error: You need to collect all coins before exiting\n");
// 		ft_error_exit("You won\n");
// 	}
// 	if (game->map->map[game->map->player_y][game->map->player_x] == 'C')
// 	{
// 		game->map->collectible--;
// 		game->map->map[game->map->player_y][game->map->player_x] = '0';
// 	}
// }
