/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:40:58 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 18:01:21 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	ft_error_free(t_map *map, char *message)
{
	if (map)
	{
		ft_free(map->map);
		free(map);
	}
	ft_error_exit(message);
}

void	ft_game_free(t_game *game, char *message)
{
	if (game->map)
	{
		ft_free(game->map->map);
		free(game->map);
	}
	ft_error_exit(message);
}
