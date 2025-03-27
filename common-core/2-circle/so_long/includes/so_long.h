/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/24 12:25:31 by mivogel          ###   ########.fr       */
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

# define WALL_L1 "./assets/wall/wall_bonus.xpm"
# define WALL_L2 "./assets/wall/wall_L2.xpm"
# define WALL_L3 "./assets/wall/wall_L3.xpm"
# define WALL_R1 "./assets/wall/wall_R1.xpm"
# define WALL_R2 "./assets/wall/wall_R2.xpm"
# define WALL_R3 "./assets/wall/wall_R3.xpm"
# define WALL_T "./assets/wall/wall_T.xpm"
# define WALL_B "./assets/wall/wall_B.xpm"
# define WALL "./assets/wall/wall.xpm"
# define FLOOR "./assets/floor/floor.xpm"
# define COIN "./assets/coin/key.xpm"
# define EXIT1 "./assets/exit/exit1.xpm"
# define EXIT2 "./assets/exit/exit2.xpm"
# define PLAYER_R1 "./assets/player/player_R1.xpm"
# define PLAYER_R2 "./assets/player/player_R22.xpm"
# define PLAYER_L1 "./assets/player/player_L1.xpm"
# define PLAYER_L2 "./assets/player/player_L22.xpm"
# define SKULL_L1 "./assets/skull/skull_L1.xpm"
# define SKULL_L2 "./assets/skull/skull_L2.xpm"
# define SKULL_R1 "./assets/skull/skull_R1.xpm"
# define SKULL_R2 "./assets/skull/skull_R2.xpm"

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
	void		*wall;
}				t_walls;

typedef struct s_player
{
	char		dir;
	void		*player_r1;
	void		*player_r2;
	void		*player_l1;
	void		*player_l2;
}				t_player;

typedef struct s_skull
{
	char		dir;
	void		*skull_l1;
	void		*skull_l2;
	void		*skull_r1;
	void		*skull_r2;
}				t_skull;

typedef struct s_sprite
{
	int			height;
	int			width;
	void		*floor;
	void		*coin;
	void		*exit1;
	void		*exit2;
	t_player	player;
	t_skull		skull;
	t_walls		walls;
}				t_sprite;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_map
{
	char		**tab;
	int			nbcoin;
	int			nbskull;
	int			height;
	int			width;
	t_coord		player;
	t_coord		*coins;
	t_coord		*skulls;
	t_coord		exit;
}				t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			mov;
	int			mov_skull;
	t_map		map;
	t_sprite	sprite;
}				t_data;

// checks
char			**ft_mapcpy(char **tab);
int				ft_check_str(char *str);
t_map			ft_map(int fd);
int				ft_parsing(t_map map);
int				ft_walls(char **tab, int len);
int				ft_contains(char **tab);
int				ft_validexit(char **tab);
// game
void			ft_draw_outerwalls(t_data *data);
void			ft_draw_inner(t_data *data, int i, int j);
void			ft_draw_player(t_data *data, int i, int j);
void			ft_draw_skull(t_data *data, int i, int j);
void			ft_draw(t_data *data);
void			*ft_load_img(t_data *data, char *path);
void			*get_wall_texture(t_data *data, int i, int j);
void			ft_img_outerwalls(t_data *data);
void			ft_img_inner(t_data *data);
void			ft_img(t_data *data);
int				ft_key(int keycode, t_data *data);
void			ft_move_up(t_data *data);
void			ft_move_down(t_data *data);
void			ft_move_left(t_data *data);
void			ft_move_right(t_data *data);
void			ft_move_skull_up(t_data *data, int i);
void			ft_move_skull_down(t_data *data, int i);
void			ft_move_skull_left(t_data *data, int i);
void			ft_move_skull_right(t_data *data, int i);
// utils
void			ft_free_map(t_map map);
void			ft_destroy_image(t_data *data);
int				ft_close(t_data *data);
t_map			ft_init_map(char *av);
int				ft_wincond(t_data *data, int i, int j);
int				ft_losecond(t_data *data, int i, int j);
void			ft_display_moves(t_data *data);
void			ft_game(t_data *data);
int				ft_countitems(char **tab, char items);
t_coord			ft_getpos(char **tab, char c);
t_coord			ft_coord(int i, int j);
t_coord			*ft_getcoins_pos(char **tab, int nbcoin);
char			**ft_readmap(int fd);
void			ft_move_skull(t_data *data);
void			ft_move_skull_1(t_data *data, int i, int x, int y);
void			ft_move_skull_2(t_data *data, int i, int x, int y);

#endif