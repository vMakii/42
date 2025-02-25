/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:25:02 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/25 14:59:48 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_printf("Usage Error: [./so_long *.ber]\n"), 1);
	map = ft_check_map(av[1]);
	ft_freetab(map.tab);
	ft_free_coins(map.coins, map.nbcoin);
	return (0);
}
