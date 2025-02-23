/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:22:49 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/23 14:50:01 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	**ft_split(char *s, char c);
void	ft_error(char *message);
char	*ft_check_map(int fd, const char *file_name);
void	ft_validate_map(char *map);
void	ft_check_len(int fd,char *file);
void checkk(int fd, const char *file_name);
void ft_check_wall(char *map);
int ft_strcmp(const char *s1, const char *s2);
int file_check(char *file);
