/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:58:38 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/14 03:37:53 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free(game->map->map);
	free(game->enemies);
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
	game.frame = 0;
	game.cycle = 0;
	ft_start_game(&game, av[1]);
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 0, ft_keypress, &game);
	mlx_hook(game.win, 17, 0, ft_close_window, &game);
	ft_enemy(&game);
	mlx_loop_hook(game.mlx, ft_animate, &game);
	mlx_loop(game.mlx);
	return (ft_free(map.map), free(game.enemies), 0);
}
