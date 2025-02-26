/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:22:49 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/25 23:54:59 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "gnl/get_next_line.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int 	player;
	int		exit;
	int		collectible;
	int 	player_x;
	int 	player_y;
}	t_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	**ft_split(char *s, char c);
void	ft_error(char *message);
char	**ft_read_map(char *filename, t_map *map);
int	ft_is_rectangular(t_map *map);
void	ft_validate_map(t_map *map);
void ft_check_chars(t_map *map);
void ft_check_walls(t_map *map);
void ft_free(char **str);
void	ft_free_struct(t_map *map);
void ft_file(char *file);
int ft_strcmp(char *s1, char *s2);
void    ft_check_path(t_map *map);
void	ft_set_map(t_map *map);
int map_width(char **map);
char **ft_parsing(t_map *map, char **av);

#endif
