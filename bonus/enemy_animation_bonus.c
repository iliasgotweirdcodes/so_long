/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:53:15 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 17:44:36 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_enemy_frames(t_game *game)
{
	game->img_demension = 32;
	game->img_enemy[0] = mlx_xpm_file_to_image(game->mlx, "textures/enemy0.xpm",
			&game->img_demension, &game->img_demension);
	game->img_enemy[1] = mlx_xpm_file_to_image(game->mlx, "textures/enemy1.xpm",
			&game->img_demension, &game->img_demension);
	game->img_enemy[2] = mlx_xpm_file_to_image(game->mlx, "textures/enemy2.xpm",
			&game->img_demension, &game->img_demension);
	game->img_enemy[3] = mlx_xpm_file_to_image(game->mlx, "textures/enemy3.xpm",
			&game->img_demension, &game->img_demension);
	game->img_enemy[4] = mlx_xpm_file_to_image(game->mlx, "textures/enemy4.xpm",
			&game->img_demension, &game->img_demension);
	if (!game->img_enemy[0] || !game->img_enemy[1] || !game->img_enemy[2]
		|| !game->img_enemy[3] || !game->img_enemy[4])
	{
		destroy_images(game);
		ft_game_free(game, "Error\nFailed to load textures\n");
	}
}

void	ft_enemy_render(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy[game->frame % 5],
		x * TILE_SIZE, y * TILE_SIZE);
}

int	ft_animate(t_game *game)
{
	int	i;

	i = 0;
	game->cycle++;
	if (game->cycle > 1200)
	{
		ft_load_img(game);
		game->frame = (game->frame + 1) % 5;
		game->cycle = 0;
		while (i < game->enemy_count)
		{
			ft_enemy_render(game, game->enemies[i].x, game->enemies[i].y);
			i++;
		}
	}
	return (0);
}

int	count_num_enm(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'X')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	ft_enemy(t_game *game)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	index = 0;
	game->enemy_count = count_num_enm(game);
	game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
	if (!game->enemies)
		return ;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'X')
			{
				game->enemies[index].x = x;
				game->enemies[index].y = y;
				index++;
			}
			x++;
		}
		y++;
	}
}
