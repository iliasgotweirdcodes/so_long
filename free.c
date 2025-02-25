/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:40:58 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/24 23:26:05 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(char **str)
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
void	ft_free_map(char **array, t_map *map)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	if (array)
	{
		while (i < map->height)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
	}
		free(array);
}
