/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:56:31 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/06 23:56:52 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_parsing(t_map **map, char **av)
{
	ft_file(av[1]);
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (0);
	ft_set_map(*map);
	(*map)->map = ft_read_map(av[1], *map);
	if (!(*map)->map)
		return (free(*map), 0);
	ft_validate_map(*map);
	ft_is_rectangular(*map);
	ft_check_chars(*map);
	ft_check_walls(*map);
	ft_check_path(*map);
	return (1);
}
