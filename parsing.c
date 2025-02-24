/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:22:37 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/24 15:39:02 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac,char **av)
{
	char **map;
	(void)ac;
	ft_file(av[1]);
	map = ft_read_map(av[1]);
	if (!map)
		return (0);
	ft_validate_map(map);
	ft_check_chars(map);
	ft_is_rectangular(map);
	ft_check_walls(map);
	int i = 0;
	while(map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}
