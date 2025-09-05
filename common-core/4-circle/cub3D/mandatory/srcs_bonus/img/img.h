/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:05:23 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 11:15:34 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

typedef struct s_image
{
	t_img	*image;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}			t_image;

typedef struct s_texture
{
	t_image	starting_screen_0;
	t_image	starting_screen_1;
	t_image	hit;
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	t_image	up_north;
	t_image	up_south;
	t_image	up_west;
	t_image	up_east;
	t_image	player_left1;
	t_image	player_left2;
	t_image	player_cast_0_l;
	t_image	player_cast_0_r;
	t_image	player_cast_1_l;
	t_image	player_cast_1_r;
	t_image	player_cast_2_l;
	t_image	player_cast_2_r;
	t_image	player_cast_3_l;
	t_image	player_cast_3_r;
	t_image	player_cast_4_l;
	t_image	player_cast_4_r;
	t_image	player_cast_5_l;
	t_image	player_cast_5_r;
	t_image	player_right1;
	t_image	player_right2;
	t_image	player_attack_0;
	t_image	player_attack_1;
	t_image	player_attack_2;
	t_image	player_attack_3;
	t_image	player_attack_4;
	t_image	player_magick_0;
	t_image	player_magick_1;
	t_image	player_magick_2;
	t_image	player_magick_3;
	t_image	player_magick_4;
	t_image	player_magick_5;
	t_image	player_magick_6;
	t_image	player_magick_7;
	t_image	player_magick_8;
	t_image	player_magick_9;
	t_image	impact_0;
	t_image	impact_1;
	t_image	impact_2;
	t_image	impact_3;
	t_image	impact_4;
	t_image	blood_0;
	t_image	blood_1;
	t_image	blood_2;
	t_image	blood_3;
	t_image	blood_4;
	t_image	minimap;
	t_image	map_frame;
	t_image	map_wall;
	t_image	map_floor;
	t_image	sky_texture;
	t_image	floor;
	t_image	ceiling;
	t_image	door_closed;
	t_image	door_half_open;
	t_image	door_open;
	t_image	up_door_closed;
	t_image	up_door_half_open;
	t_image	up_door_open;
	t_image	lamp_0;
	t_image	lamp_1;
	t_image	lamp_2;
	t_image	lamp_3;
	t_image	sprites_ceiling[NB_SPRITES_C];
	t_image	sprites_floor[NB_SPRITES_F];
	t_image	treasure;
	t_image	bar;
	t_image	health_bar;
	t_image	stamina_bar;
	t_image	magic_bar;
	t_image	cursor;
	t_image	death_screen;
	t_image	werewolf_moving_0;
	t_image	werewolf_moving_1;
	t_image	werewolf_moving_2;
	t_image	werewolf_moving_3;
	t_image	werewolf_attack_0;
	t_image	werewolf_attack_1;
	t_image	werewolf_attack_2;
	t_image	werewolf_damaged;
	t_image	werewolf_dead;
	t_image	skeleton_moving_0;
	t_image	skeleton_moving_1;
	t_image	skeleton_moving_2;
	t_image	skeleton_moving_3;
	t_image	skeleton_attack_0;
	t_image	skeleton_attack_1;
	t_image	skeleton_attack_2;
	t_image	skeleton_attack_3;
	t_image	skeleton_attack_4;
	t_image	skeleton_attack_5;
	t_image	skeleton_damaged;
	t_image	skeleton_dead;
	t_image	zombie_moving_0;
	t_image	zombie_moving_1;
	t_image	zombie_moving_2;
	t_image	zombie_moving_3;
	t_image	zombie_moving_4;
	t_image	zombie_moving_5;
	t_image	zombie_moving_6;
	t_image	zombie_moving_7;
	t_image	zombie_attack_0;
	t_image	zombie_attack_1;
	t_image	zombie_attack_2;
	t_image	zombie_attack_3;
	t_image	zombie_attack_4;
	t_image	zombie_damaged;
	t_image	zombie_dead;
}			t_texture;

// destroy
void		destroy_effects(t_data *data);
void		destroy_enemies(t_data *data);
void		destroy_player(t_data *data);
void		destroy_magick(t_data *data);
void		destroy_sprites(t_data *data);
void		destroy_textures(t_data *data);

// img
void		load_img(t_data *data, t_image *sprite, char *path);
void		init_img(t_data *data);
void		destroy_img(t_data *data);

// load
void		load_effects(t_data *data);
void		load_enemies(t_data *data);
void		load_player(t_data *data);
void		load_magick(t_data *data);
void		load_sprites(t_data *data);
void		load_screens(t_data *data);
void		load_textures(t_data *data);

#endif