/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:04:14 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/25 15:00:03 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_coins(t_coord *coins, int nbcoin)
{
	int	i;

	i = 0;
	while (i < nbcoin)
	{
		free(&coins[i]);
		i++;
	}
	free(coins);
}

void	ft_exit_map(t_map map)
{
	ft_freetab(map.tab);
	ft_free_coins(map.coins, map.nbcoin);
	exit(0);
}
