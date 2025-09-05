/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:04:33 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 12:41:52 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef enum weapon_type
{
	FIST,
	SWORD,
	MAGIC_SWORD,
}					t_weapon_type;

typedef enum action
{
	IDLE,
	WALKING,
	RUNNING,
	ATTACKING,
	CASTING,
}					t_action;

typedef enum impact
{
	BASE,
	BLOOD,
}					t_impact;

typedef struct s_weapons
{
	t_weapon_type	type;
	int				damage;
	float			range;
}					t_weapons;

typedef struct s_magick
{
	t_image			*hand_left;
	t_image			*hand_right;
	t_image			*spell;
	bool			casted;
	bool			casting;
	bool			cd;
}					t_magick;

typedef struct s_player
{
	t_coord_float	pos;
	t_coord_float	dir;
	t_coord_float	plane;
	float			angle;
	int				hp;
	int				mp;
	int				is_hit;
	t_action		action;
	t_weapons		weapon;
	t_magick		magick;
	int				impact;
	t_impact		impact_effect;
	int				impact_zone;
	float			central_ray_distance;
	int				central_ray_map_x;
	int				central_ray_map_y;
}					t_player;

// Player rendering
void				init_player(t_data *data);
void				render_player(t_data *data);
void				render_player_idle(t_data *data);
void				render_player_walking(t_data *data, double current_time);
void				render_player_running(t_data *data, double current_time);
void				render_player_attacking(t_data *data, double current_time);
void				render_player_casting(t_data *data);
void				render_spell_effect(t_data *data);
void				render_player_magick(t_data *data);
void				change_weapons(t_data *data);
void				init_weapons(t_data *data);
void				combat_player(t_data *data);

#endif
