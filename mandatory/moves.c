/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:04:57 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/05 03:33:15 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_valid_move(t_map *map, int x, int y)
{
	if (!map || !map->map)
		return (0);
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);
	if (!map->map[y])
		return (0);
	if (map->map[y][x] == '1')
		return (0);
	return (1);
}

void	ft_update_player(t_game *game, t_map *map, int x, int y)
{
	if (map->map[game->player_y][game->player_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	if (map->map[game->player_y][game->player_x] == 'E')
		map->map[game->player_y][game->player_x] = 'E';
	else
		map->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	if (map->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		x * TILE_SIZE, y * TILE_SIZE);
}

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
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"textures/opened_exit.xpm",
				&game->map->width, &game->map->height);
		if (!game->img_exit)
			ft_error_exit("Error: Failed to load image\n");
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			map->exit_x * TILE_SIZE, map->exit_y * TILE_SIZE);
		if (map->map[y][x] == 'E' && game->map->collectible == 0)
			ft_moves_win(game);
	}
}

void	ft_move(t_game *game, t_map *map, int dx, int dy)
{
	int	x;
	int	y;

	x = game->player_x + dx;
	y = game->player_y + dy;
	ft_player(game, map);
	ft_exit(map, game);
	if (ft_valid_move(map, x, y))
	{
		game->moves++;
		ft_update_player(game, map, x, y);
		ft_collectible_exit(game, map, x, y);
		write(1, "\033[1;32mMoves: ", 15);
		ft_putnbr(game->moves);
		write(1, "\n", 1);
	}
	else
		return ;
}

int	ft_keypress(int key, t_game *game)
{
	if (key == KEY_W)
		ft_move(game, game->map, 0, -1);
	else if (key == KEY_A)
		ft_move(game, game->map, -1, 0);
	else if (key == KEY_S)
		ft_move(game, game->map, 0, 1);
	else if (key == KEY_D)
		ft_move(game, game->map, 1, 0);
	else if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}
