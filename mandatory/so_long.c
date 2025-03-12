/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:24:42 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 16:55:01 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	ft_free(game->map->map);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	error(t_map *map)
{
	ft_free(map->map);
	free(map);
	ft_error_exit("Error\nFailed to initialize MLX\n");
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	game;

	if (ac != 2)
		ft_error_exit("Error\nInvalid number of arguments.\n");
	map = NULL;
	if (!ft_parsing(&map, av))
		return (ft_free(map->map), 1);
	game.map = map;
	game.mlx = mlx_init();
	if (!game.mlx)
		error(map);
	game.moves = 0;
	ft_start_game(&game, av[1]);
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 0, ft_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (ft_free(map->map), free(map), 0);
}
