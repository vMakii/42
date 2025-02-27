/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/27 12:14:42 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stdio.h>

// # define ESC 53

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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}			t_data;

// check_map
char		**ft_mapcpy(char **tab);
void		ft_printmap(char **tab);
int			ft_check_str(char *str);
t_map		ft_map(int fd);
int			ft_parsing(t_map map);
// parsing
int			ft_walls(char **tab, int len);
int			ft_contains(char **tab);
int			ft_validexit(char **tab);
// free_utils
void		ft_free_map(t_map map);
// map_utils
int			ft_countcoins(char **tab);
t_coord		ft_getpos(char **tab, char c);
t_coord		ft_coord(int i, int j);
t_coord		*ft_getcoins_pos(char **tab, int nbcoin);
char		**ft_readmap(int fd);

#endif
