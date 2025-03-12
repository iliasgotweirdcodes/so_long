/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:40:21 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/12 17:08:14 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"

# define TILE_SIZE 32

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_X 17

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		collectible;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	int		enemy;
}	t_map;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_exit_open;
	int		img_demension;
	void	*img_enemy[5];
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		moves;
	int		frame;
	int		cycle;
	t_map	*map;
	t_enemy	*enemies;
	int		enemy_count;
}	t_game;

typedef struct s_char
{
	char	e;
	char	c;
	char	p;
	char	x;
}	t_char;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
void	ft_error(char *message);
void	ft_error_exit(char *message);
char	**ft_read_map(char *filename, t_map *map);
int		ft_is_rectangular(t_map *map);
void	ft_validate_map(t_map *map);
void	ft_check_chars(t_map *map);
void	ft_check_walls(t_map *map);
void	ft_free(char **str);
void	ft_file(char *file);
int		ft_strcmp(char *s1, char *s2);
void	ft_check_path(t_map *map);
void	ft_set_map(t_map *map);
int		map_width(char **map);
int		ft_parsing(t_map **map, char **av);
int		count_map(int fd);
void	ft_start_game(t_game *game, char *filename);
void	ft_load_img(t_game *game);
void	ft_decide_comp(t_game *game, int x, int y);
void	ft_draw_map(t_game *game);
int		ft_keypress(int key, t_game *game);
void	ft_player(t_game *game, t_map *map);
void	ft_exit(t_map *map, t_game *game);
void	destroy_images(t_game *game);
void	ft_win(t_game *game);
void	ft_error_free(t_map *map, char *message);
char	*ft_itoa(int n);
void	ft_put_str_win(t_game *game);
void	ft_found_enemy(t_map *map, t_game *game, int x, int y);
int		ft_animate(t_game *game);
void	ft_enemy(t_game *game);
void	ft_enemy_render(t_game *game, int x, int y);
void	ft_enemy_frames(t_game *game);
void	ft_collectible_exit(t_game *game, t_map *map, int x, int y);
void	ft_error_free(t_map *map, char *message);
void	ft_out_of_screen(t_map *map);

#endif
