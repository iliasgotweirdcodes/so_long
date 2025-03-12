/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:25:10 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 17:48:27 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_out_of_screen(t_map *map)
{
	if (map->width > 80 || map->height > 41)
	{
		ft_free(map->map);
		free(map);
		ft_error_free(map, "Error\nmap too big lol\n");
	}
}
