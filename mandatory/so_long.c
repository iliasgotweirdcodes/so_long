/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:24:42 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/14 03:36:38 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free(game->map->map);
	exit(0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;

	if (ac != 2)
		ft_error_exit("Error\nInvalid number of arguments.\n");
	if (!ft_parsing(&map, av))
		return (1);
	game.map = &map;
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_free(map.map);
		ft_error_exit("Error\nFailed to initialize MLX\n");
	}
	game.moves = 0;
	ft_start_game(&game, av[1]);
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 0, ft_keypress, &game);
	mlx_hook(game.win, 17, 0, ft_close_window, &game);
	mlx_loop(game.mlx);
	return (ft_free(map.map), 0);
}
