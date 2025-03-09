/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:55:17 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/09 02:10:00 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_valid_move(t_map *map, int x, int y)
{
	if (!map || !map->map)
		return (0);
	if (x < 0 || y < 0 || x > map->width || y > map->height)
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
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open,
			map->exit_x * TILE_SIZE, map->exit_y * TILE_SIZE);
		if (map->map[y][x] == 'E' && game->map->collectible == 0)
			ft_win(game);
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
		ft_found_enemy(map, game, x, y);
	}
	else
		return ;
}


int	ft_keypress(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
		ft_move(game, game->map, 0, -1);
	else if (key == KEY_A || key == KEY_LEFT)
		ft_move(game, game->map, -1, 0);
	else if (key == KEY_S || key == KEY_DOWN)
		ft_move(game, game->map, 0, 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		ft_move(game, game->map, 1, 0);
	else if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_free(game->map->map);
		free(game);
		exit(0);
	}
	ft_put_str_win(game);
	return (0);
}
