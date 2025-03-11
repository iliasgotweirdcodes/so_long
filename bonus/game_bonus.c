/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:54:41 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/11 01:33:00 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	destroy_images(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

void	ft_start_game(t_game *game, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error\nFile does not exist.\n");
	if (!game->mlx)
	{
		close (fd);
		free(game);
		ft_error_exit("Error\nFailed to initialize MLX\n");
	}
	game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		close (fd);
		ft_free(game->map->map);
		free(game->map);
		free(game);
		ft_error_exit("Error\nFailed to create window\n");
	}
	close (fd);
}

void	ft_load_img(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/vampire.xpm",
			&game->map->width, &game->map->height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->map->width, &game->map->height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->map->width, &game->map->height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/blood.xpm", &game->map->width, &game->map->height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/closed_exit.xpm", &game->map->width, &game->map->height);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/opened_exit.xpm", &game->map->width, &game->map->height);
	ft_enemy_frames(game);
	if (!game->img_player || !game->img_wall || !game->img_floor
		|| !game->img_collectible || !game->img_exit || !game->img_exit_open
		|| !game->img_enemy[0] || !game->img_enemy[1] || !game->img_enemy[2]
		|| !game->img_enemy[3] || !game->img_enemy[4])
	{
		destroy_images(game);
		ft_free(game->map->map);
		free(game->map);
		free(game);
		ft_error_exit("Error\nFailed to load textures\n");
	}
}

void	ft_decide_comp(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
		game->map->collectible++;
	}
	else if (game->map->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'X')
		ft_enemy_render(game, x, y);
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->moves = 0;
	ft_load_img(game);
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				x * TILE_SIZE, y * TILE_SIZE);
			ft_decide_comp(game, x, y);
			x++;
		}
		y++;
	}
	ft_put_str_win(game);
}
