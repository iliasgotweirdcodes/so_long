/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:59:13 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/06 23:59:20 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strcmp(&file[len - 4], ".ber") != 0)
	{
		ft_error("Error\nFile name must end with .ber\n");
		exit(1);
	}
}
