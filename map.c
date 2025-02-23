/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:11:45 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/23 14:48:41 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_check_map(int fd, const char *file_name)
{
	char *map = ft_strdup("");
	char *line;
	char *tmp;
	fd = open(file_name, O_RDONLY);

	if (!map)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		ft_error("Error: Empty map\n");
		close(fd);
		exit(1);
	}
	while (line)
	{
		tmp = ft_strjoin(map, line);
		free(map);
		free(line);
		if (!tmp)
			return (NULL);
		map = tmp;
		line = get_next_line(fd);
	}
	return (map);
}

void	ft_validate_map(char *map)
{
	int	player = 0;
	int	door = 0;
	int	collectible = 0;
	int	i = 0;

	while (map[i])
	{
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'E')
			door++;
		else if (map[i] == 'C')
			collectible++;
		i++;
	}
	if (player != 1 || door != 1 || collectible < 1)
	{
		ft_error("Error: Invalid map\n");
		exit(1);
	}
}

void ft_check_len(int fd, char *file)
{
    char *line1 = NULL;
    char *line2 = NULL;

    fd = open(file, O_RDONLY);
    line1 = get_next_line(fd);
    line2 = get_next_line(fd);
    while(line1 && line2)
    {
        if (ft_strlen(line1) != ft_strlen(line2))
        {
            ft_error("Error: Invalid map\n");
			close(fd);
            exit(1);
        }
        free(line1);
        line1 = line2;
        line2 = get_next_line(fd);
    }
    close(fd);
}

void checkk(int fd, const char *file_name)
{
	int    i;
	int    line_end;
	char    *str;

	i = 0;
	str = ft_check_map(fd, file_name);
	while (str[i])
	{
		if (i == 0 || str[i - 1] == '\n')
		{
			line_end = i;
			while (str[line_end] != '\n' && str[line_end] != '\0')
				line_end++;
			if (str[i] != '1')
			{
				ft_error("Error: The first character of the line is not '1'.");
				exit(1);
			}
			if (str[line_end - 1] != '1')
			{
				ft_error("Error: The last character of the line is not '1'.");
				exit(1);
			}
		}
		i++;
	}
	free(str);
}

void ft_check_wall(char *map)
{
    int i = 0;

    while (map[i])
    {
        if (map[i] != '1' && map[i] != '\n')
        {
            ft_error("Error: Invalid map\n");
            exit(1);
        }
        i++;
    }
}

int file_check(char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    i--;
    while (file[i] && file[i] != '.')
        i--;
    if (ft_strcmp(&file[i], ".ber") == 0)
        return (0);
    return (1);
}
