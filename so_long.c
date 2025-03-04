/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:24:42 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/04 03:12:20 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 void f()
{
    system("lsof -c so_long");
    system("leaks -q so_long");
}

int	main(int ac , char **av)
{
	// atexit(f);
	t_map *map;
	t_game game;

	map = NULL;
	if (ac != 2)
		ft_error_exit("Error: Invalid number of arguments.\n");
	if (!ft_parsing(&map, av))
	{
		ft_free(map->map);
		return (1);
	}
	game.map = map;
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_free(map->map);
		free(map);
		ft_error_exit("Error: Failed to initialize MLX\n");
	}
	ft_start_game(&game, av[1]);
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 0, ft_keypress, &game);
	mlx_loop(game.mlx);
	ft_free(map->map);
	free(map);
	return (0);
}
