/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:53:19 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/03/06 23:53:31 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_error(char *message)
{
	write(2, message, ft_strlen(message));
}

void	ft_error_exit(char *message)
{
	ft_error(message);
	exit (1);
}
