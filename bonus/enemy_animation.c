/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:53:15 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/09 02:59:26 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
int	ft_animate(t_game *game)
{
    game->cycle++;
    if (game->cycle > 1200)
    {
		ft_load_img(game);
		game->frame = (game->frame + 1) % 5;
		game->cycle = 0;
		ft_decide_comp(game,game->enemy_x, game->enemy_y);
	}
	return (0);
}

void ft_enemy(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'X')
			{
				game->enemy_x = x;
				game->enemy_y = y;
			}
			x++;
		}
		y++;
	}
}

