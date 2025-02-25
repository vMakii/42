/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/25 15:01:25 by mivogel          ###   ########.fr       */
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
	int		nbcoin;
	t_coord	player;
	t_coord	*coins;
	t_coord	exit;
}			t_map;

void		ft_free_coins(t_coord *coins, int nbcoin);
// check_map
char		**ft_readmap(int fd);
char		**ft_mapcpy(char **tab);
void		ft_printmap(char **tab);
void		ft_parsing(t_map map);
t_map		ft_check_map(char *av);
// parsing
int			ft_walls(char **tab, int len);
int			ft_contains(char **tab);
void		ft_floodfill(char **tab, int x, int y);
int			ft_validexit(char **tab);
// map_utils
int			ft_countcoins(char **tab);
t_coord		ft_getpos(char **tab, char c);
t_coord		ft_coord(int i, int j);
t_coord		*ft_getcoins_pos(char **tab, int nbcoin);
t_map		ft_map(int fd);
#endif
