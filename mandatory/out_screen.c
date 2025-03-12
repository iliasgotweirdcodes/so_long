/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:31:45 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 18:10:08 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_out_of_screen(t_map *map)
{
	if (map->width > 80 || map->height > 41)
	{
		ft_error_free(map, "Error\nmap too big lol\n");
	}
}
