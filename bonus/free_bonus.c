/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:53:34 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 22:58:59 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	}
	free(str);
}

void	ft_error_free(t_map *map, char *message)
{
	if (map)
	{
		ft_free(map->map);
	}
	ft_error_exit(message);
}

void	ft_game_free(t_game *game, char *message)
{
	if (game->map)
	{
		ft_free(game->map->map);
	}
	ft_error_exit(message);
}
