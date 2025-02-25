/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:06:45 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/25 00:46:59 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **dup_map(char **map, int rows)
{
    char    **cmap;
    int        i;
    int        j;

    if (rows <= 0)
        return NULL;
    i = 0;
    j = 0;
    cmap = malloc(sizeof(char *) * (rows + 1));
    if (!cmap)
        return (NULL);
    while (map[i])
    {
        cmap[j] = ft_strdup(map[i]);
        if (!cmap[j])
            return (free(cmap), NULL);
        j++;
        i++;
    }
    cmap[j] = NULL;
    return (cmap);
}

void    flood_fill(char **map, int x, int y, int rows, int cols)
{
    if (x >= rows || y >= cols || x < 0 || y < 0)
        return ;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, rows, cols);
    flood_fill(map, x - 1, y, rows, cols);
    flood_fill(map, x, y + 1, rows, cols);
    flood_fill(map, x, y - 1, rows, cols);
}

int    *find_player(char **map)
{
    int    i;
    int    j;
    int    *pos;

    i = 0;
    pos = malloc(sizeof(int) * 2);
    if (!pos)
        return (NULL);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                pos[0] = i;
                pos[1] = j;
                return (pos);
            }
            j++;
        }
        i++;
    }
    free(pos);
    return (NULL);
}

void    ft_check_path(char **map)
{
    char    **cmap;
    int        *player;
    int        k;
    int        i;
    int        j;

    player = find_player(map);
    if (!player)
        exit(1);
    i = -1;
    while (map[++i]);
    cmap = dup_map(map, i);
    flood_fill(cmap, player[1], player[0], ft_strlen(map[0]), i);

    j = -1;
    while (map[++j])
    {
        k = -1;
        while (map[j][++k])
        {
            if (map[j][k] == 'C' || map[j][k] == 'E')
                if (cmap[j][k] != 'F')
                {
                    ft_error("Invalid Path\n");
                    exit(1);
                }
        }
    }
}
