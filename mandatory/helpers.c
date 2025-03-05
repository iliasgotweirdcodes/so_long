/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:32:26 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/05 03:33:07 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	ft_moves_win(t_game *game)
{
	write(1, "\033[1;32mMoves: ", 15);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	write(1, "\033[1;32mYou won!\033[0m\n", 21);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
