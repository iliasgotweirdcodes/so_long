/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:48:06 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 03:24:36 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_set_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->collectible = 0;
	map->exit = 0;
}
