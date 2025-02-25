/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:22:37 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/25 14:09:27 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	**ft_parse_map(char *filename)
// {
// 	char **map;
// 	ft_file(filename);  // Check if file exists
// 	map = ft_read_map(filename);
// 	if (!map)
// 		return (NULL);
// 	ft_validate_map(map);   // Check for required elements (P, E, C)
// 	ft_check_chars(map);    // Ensure only valid characters are used
// 	ft_is_rectangular(map); // Ensure map is rectangular
// 	ft_check_walls(map);    // Ensure the map is surrounded by walls
// 	invalid_path(map);      // Ensure there is a valid path from P to E
// 	return (map); // Return the validated map
// }

int main(int ac,char **av)
{
	char **map;
	if (ac != 2)
	{
		ft_error("Usage: ./so_long <map_file>\n");
		return (1);
	}
	ft_file(av[1]);
	map = ft_read_map(av[1]);
	if (!map)
		return (1);
	ft_validate_map(map);
	ft_check_chars(map);
	ft_is_rectangular(map);
	ft_check_walls(map);
	ft_check_path(map);
}
