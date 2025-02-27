/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/27 16:42:12 by mivogel          ###   ########.fr       */
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

# define WALL_L1 "./assets/wall/wall_L1.xpm"
# define WALL_L2 "./assets/wall/wall_L2.xpm"
# define WALL_L3 "./assets/wall/wall_L3.xpm"
# define WALL_R1 "./assets/wall/wall_R1.xpm"
# define WALL_R2 "./assets/wall/wall_R2.xpm"
# define WALL_R3 "./assets/wall/wall_R3.xpm"
# define WALL_T "./assets/wall/wall_T.xpm"
# define WALL_B "./assets/wall/wall_B.xpm"

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_map
{
	char		**tab;
	int			nb;
	int			nbcoin;
	int			height;
	int			width;
	t_coord		player;
	t_coord		*coins;
	t_coord		exit;
}				t_map;

typedef struct s_walls
{
	void		*wall_l1;
	void		*wall_l2;
	void		*wall_l3;
	void		*wall_r1;
	void		*wall_r2;
	void		*wall_r3;
	void		*wall_t;
	void		*wall_b;
}				t_walls;

typedef struct s_sprite
{
	int			height;
	int			width;
	t_walls		walls;
}				t_sprite;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			mov;
	t_map		map;
	t_sprite	sprite;
}				t_data;

// check_map
char			**ft_mapcpy(char **tab);
void			ft_printmap(char **tab);
int				ft_check_str(char *str);
t_map			ft_map(int fd);
int				ft_parsing(t_map map);
// parsing
int				ft_walls(char **tab, int len);
int				ft_contains(char **tab);
int				ft_validexit(char **tab);
// free_utils
void			ft_free_map(t_map map);
// map_utils
int				ft_countcoins(char **tab);
t_coord			ft_getpos(char **tab, char c);
t_coord			ft_coord(int i, int j);
t_coord			*ft_getcoins_pos(char **tab, int nbcoin);
char			**ft_readmap(int fd);

#endif
