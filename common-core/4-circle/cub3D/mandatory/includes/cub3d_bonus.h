/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:27:13 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 11:04:28 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

// Include all library headers
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
# include <time.h>
# include <unistd.h>

// Include all module headers
# include "doors.h"
# include "effects.h"
# include "enemies.h"
# include "hud.h"
# include "img.h"
# include "inputs.h"
# include "loop.h"
# include "move.h"
# include "parsing.h"
# include "player.h"
# include "raycasting.h"
# include "screens.h"
# include "sprites.h"
# include "utils.h"

// Constants
# define WIN_WIDTH 1333
# define WIN_HEIGHT 1000

# define NB_SPRITES_C 2
# define NB_SPRITES_F 18

# define RANDOM_C 'C'
# define RANDOM_F 'F'

// # define RANDOM_CEILING 'C'
// # define RANDOM_STATUES 'T'
// # define RANDOM_LOOT 'F'
// # define RANDOM_SHELVES 'H'

// # define GRAAL 'G'
# define TREASURE 'T'
# define LAMP 'L'

# define ENEMY 'M'

# define WALL '1'
# define FLOOR '0'
# define DOOR 'D'

# define WALL_TEX_WIDTH 128
# define WALL_TEX_HEIGHT 128

# define FLOOR_TEX_WIDTH 128
# define FLOOR_TEX_HEIGHT 128

# define CEILING_TEX_WIDTH 64
# define CEILING_TEX_HEIGHT 64

# define DOOR_TEX_WIDTH 128
# define DOOR_TEX_HEIGHT 128

# define VERT_HIT 0
# define HORI_HIT 1

# define MINIMAP_SCALE 12 // 12
# define MINIMAP_OFFSET 5

# define HUDSCALING 4
# define UPSCALING 5
# define BIGSCALING 10

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000
# define COLOR_YELLOW 0xFFFF00
# define COLOR_GREY 0x808080

# define FOV 60

# define WALK_SPEED 0.04f
# define TURN_SPEED 0.04f
# define RUN_SPEED 0.08f
# define MARGIN 0.1f

# define INTERACTION_DISTANCE 1.0f

extern int							g_frame_count;

// Basic coordinate types
typedef struct s_coord_int
{
	int								x;
	int								y;
}									t_coord_int;

typedef struct s_coord_float
{
	float							x;
	float							y;
}									t_coord_float;

typedef struct s_mlx
{
	void							*ptr;
	void							*win;
	int								width;
	int								height;
}									t_mlx;

// Forward declarations for all main types
typedef struct s_data				t_data;
typedef struct s_door				t_door;
typedef struct s_door_list			t_door_list;
typedef struct s_sprite				t_sprite;
typedef struct s_ray				t_ray;
typedef struct s_player				t_player;
typedef struct s_texture			t_texture;
typedef struct s_image				t_image;
typedef struct s_key				t_key;
typedef struct s_minimap			t_minimap;
typedef struct s_time				t_time;
typedef struct s_file				t_file;
typedef struct s_garbage			t_garbage;
typedef struct s_rect				t_rect;
typedef struct s_starting_screen	t_starting_screen;

// Define main data structure here
typedef struct s_data
{
	char							**map;
	t_file							file;
	t_mlx							mlx;
	t_starting_screen				starting_screen;
	t_time							time;
	t_player						player;
	t_garbage						*gc_list;
	t_texture						texture;
	t_door_list						doors;
	t_image							frame;
	t_key							keys;
	t_minimap						minimap;
	t_sprite						*sprite;
	t_enemy							*enemy;
	float							z_buffer[WIN_WIDTH];
}									t_data;

#endif