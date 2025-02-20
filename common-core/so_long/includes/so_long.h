/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/20 14:07:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_map
{
	char	**tab;
	int		nb;
	int		mov;
	t_coord	player;
	t_coord	*coin;
	t_coord	exit;
}			t_map;

int			ft_check_map(char *av);
// parsing
int			ft_walls(char **tab, int len);
int			ft_contains(char **tab);
void		ft_parsing(char **tab, int len);

#endif
