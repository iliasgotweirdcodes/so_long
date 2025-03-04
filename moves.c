/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:04:57 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/04 02:58:18 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_player(t_game *game , t_map *map)
{
    int    i;
    int    j;

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

void ft_exit(t_map *map , t_game *game)
{
	int i;
	int j;

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
int ft_valid_move(t_map *map, int x, int y)
{
    // Ensure the map exists before accessing it
    if (!map || !map->map)
        return (0);
    // Check if the move is within the bounds of the map
    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        return (0);
    // Ensure the row exists before accessing it
    if (!map->map[y])
        return (0);
    // Check if the position is a wall
    if (map->map[y][x] == '1')
        return (0);
    return (1);
}


void ft_update_player(t_game *game, t_map *map, int x, int y)
{
	if (map->map[game->player_y][game->player_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,  game->player_x * TILE_SIZE,  game->player_y * TILE_SIZE);
	if (map->map[game->player_y][game->player_x] == 'E')
		map->map[game->player_y][game->player_x] = 'E';
	else
		map->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	if (map->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
}
void ft_collectible_exit(t_game *game,t_map *map, int x, int y)
{
	if (map->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
		game->map->collectible--;
	}
	if (game->map->collectible == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/opened_exit.xpm", &game->map->width, &game->map->height);
		if (!game->img_exit)
			ft_error_exit("Error: Failed to load image\n");
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, map->exit_y * TILE_SIZE, map->exit_x * TILE_SIZE);
		if (map->map[y][x] == 'E' && game->map->collectible == 0)
		{
			write(1, "You won!\n", 9);
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
	}
}

 void    ft_move(t_game *game, t_map *map, int dx, int dy)
{
    int    x;
    int    y;

	ft_player(game, map);
	ft_exit(map, game);
    x = game->player_x + dx;
    y = game->player_y + dy;
    // Check if the new position is valid
    if (!ft_valid_move(map, x, y))
    {
		write(2, "Invalid move\n", 13);
			return ;
    }
    // Update the player's position and redraw the map
    ft_update_player(game,map, x, y);
    // Handle collectibles and exit logic
    ft_collectible_exit(game, map, x, y);

    printf("Player moved to: (%d, %d)\n", x, y);
    //printf("moved (%d) time\n", i++);
    // printf("Collectibles remaining: %d\n", game->map->collectible);
    // count_moves();
}
int ft_keypress(int key, t_game *game)
{
	if (key == KEY_W)
	{
		ft_move(game, game->map, 0, -1);
	}
	else if (key == KEY_A)
	{
		ft_move(game, game->map, -1, 0);
	}
	else if (key == KEY_S)
	{
		ft_move(game, game->map, 0, 1);
	}
	else if (key == KEY_D)
	{
		ft_move(game, game->map, 1, 0);
	}
	else if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}
