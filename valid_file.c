/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:26:59 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/24 15:25:53 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_file(char *file)
{
	int	len;
	len = ft_strlen(file);

	if (len < 4 || ft_strcmp(&file[len - 4], ".ber") != 0)
	{
		ft_error( "Error: File name must end with .ber\n");
		exit(1);
	}
}
