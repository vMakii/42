/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:27:13 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 18:08:49 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define WIN_WIDTH 1333
# define WIN_HEIGHT 1000

# define WALL '1'
# define FLOOR '0'

# define MINIMAP_SCALE 15
# define UPSCALING 5

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000
# define COLOR_YELLOW 0xFFFF00

extern int frame_count;

typedef struct s_keys
{
	int					key_a;
	int					key_d;
	int					key_w;
	int					key_s;
	int					key_left;
	int					key_right;
	int					key_up;
	int					key_down;
}						t_keys;

typedef enum action
{
	IDLE,
	MOVING,
	ATTACKING,
}						t_action;

typedef struct s_rect
{
	float				x;
	float				y;
	float				width;
	float				height;
}						t_rect;

typedef struct s_garbage
{
	void				*alloc;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_sprite
{
	int					width;
	int					height;
	void				*img;
}						t_sprite;

typedef struct s_sprite_list
{
	t_sprite			north;
	t_sprite			south;
	t_sprite			west;
	t_sprite			east;
	t_sprite			player_left1;
	t_sprite			player_left2;
	t_sprite			player_right1;
	t_sprite			player_right2;
	t_sprite			player_sword1;
	// t_sprite			player_sword2;
}						t_sprite_list;

typedef struct s_texture
{
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					floor_color;
	int					ceiling_color;
}						t_texture;

typedef struct s_map
{
	char				*str;
	char				**tab;
	char				**map;
	int					player[2];
}						t_map;

typedef struct s_pos
{
	float				posX;
	float				posY;
	float				dirX;
	float				dirY;
	float				angle;
}						t_pos;

typedef struct s_player
{
	t_pos				pos;
	int hp; // health points
	int mp; // mana points
	t_action			action;
}						t_player;

typedef struct s_mlx
{
	void				*ptr;
	void				*win;
	int					width;
	int					height;
}						t_mlx;

typedef struct s_time
{
	float time;      // time of current frame
	float oldTime;   // time of previous frame
	float frameTime; // frameTime is the time this frame has taken, in seconds
	int FPS;          // FPS counter
}						t_time;

typedef struct s_data
{
	t_map				map;
	t_mlx				mlx;
	t_time				time;
	t_pos				player;
	t_player			player_data;
	t_garbage			*gc_list;
	t_sprite_list		sprite_list;
	t_img				frame;
	t_texture			texture;
	t_keys				keys;
}						t_data;

// keypress
// void					update_player_status(t_data *data, t_action action);
int						handle_keypress(int keysym, t_data *data);
int						handle_keyrelease(int keysym, t_data *data);
void					player_move(t_data *data);

// raycasting
void					raycasting(t_data *data);

// Garbage Collector
void					*gc_malloc(size_t size, t_garbage **gc_list);
void					*gc_add_malloc(void *ptr, t_garbage **gc_list);
char					**gc_add_tab(char **tab, t_garbage **gc_list);
void					gc_free(t_garbage **gc_list);

// Img
void					init_img(t_data *data);
void					upscale_img(t_data *data, t_sprite *sprite, int scale,
							int dest_x, int dest_y);
void					upscale_img_to_frame(t_data *data, t_action action);
void					destroy_img(t_data *data);
int						render_frame(t_data *data);
void					render_minimap(t_data *data);

// Img utils
int						RGB(u_int8_t r, u_int8_t g, u_int8_t b);
int						pix_index(t_img *img, int x, int y);
void					img_pix_put(t_img *img, int x, int y, int color);
int						render_rect(t_img *img, t_rect rect, int color);
void					init_rect(t_rect *rect, float size);
void					draw_line(t_img *img, int x1, int y1, int x2, int y2, int color);

// parsing
void					parsing(int argc, char **argv, t_data *data);
bool					read_file(char *filename, t_data *data);
bool					check_data(t_data *data);
bool					check_map(t_data *data);
bool					check_map_nl(char *str);
bool					get_data(t_data *data);
bool					get_map(t_data *data);
bool					check_filename(char *filename, char *ext);

// close
int						exit_failure(t_data *data, char *str);
int						exit_success(t_data *data);

// free
void					free_all(t_data *data);

// print
void					print_data_map(t_data data);

// utils
int						signof(float value);

#endif