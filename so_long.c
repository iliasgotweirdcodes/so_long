/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:24:42 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/26 00:30:36 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_args(int ac)
{
	if (ac != 2)
	{
		ft_error("Usage: ./so_long <map_file>\n");
		exit(1);
	}
}

 void f()
{
    system("lsof -c so_long");
    system("leaks -q so_long");
}
int	main(int ac , char **av)
{
	atexit(f);
	t_map *map;
	char **map1;

	map = NULL;
	ft_handle_args(ac);
	map1 = ft_parsing(map, av);
	ft_free(map1);
	return (0);
}
