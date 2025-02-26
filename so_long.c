/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:24:42 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/26 18:14:55 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void ft_mlx(void)
{
	void *mlx;
	void *win;
	void *img;
	int height = 32;
	int width = 32;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 920, 620, "so_long");
	img = mlx_xpm_file_to_image(mlx, "floor.xpm", &height,&width);
	mlx_loop(mlx);

}

 void f()
{
    system("lsof -c so_long");
    system("leaks -q so_long");
}
#include <stdio.h>
int	main(int ac , char **av)
{
	atexit(f);
	t_map *map;

	map = NULL;
	if (ac != 2)
		ft_error_exit("Error: Invalid number of arguments.\n");
	if (!ft_parsing(&map, av))
	{
		ft_free(map->map);
		return (1);
	}
	ft_free(map->map);
	return (0);
}
