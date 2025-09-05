/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:39:20 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 18:59:27 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H

typedef enum e_enemy_type
{
	WEREWOLF,
	SKELETON,
	ZOMBIE
}					t_enemy_type;

typedef enum e_state_enemy
{
	STANDING,
	MOVING,
	ATTACK,
	DAMAGED,
	DEAD
}					t_state_enemy;

typedef struct s_enemy
{
	t_sprite		*sprite;
	t_enemy_type	type;
	t_state_enemy	state;
	int				hp;
	float			speed;
	float			attack_range;
	int				attack_cooldown;
	int				attack_timer;
	int				attack_damage;
	int				attack_speed;
	bool			attack_hit;
	struct s_enemy	*next;
}					t_enemy;

// main
void				update_enemies(t_data *data);

// init
void				init_enemy(t_data *data);

// animation
void				update_animated_enemies(t_data *data);
void				update_skeleton(t_enemy *current, t_data *data);
void				update_werewolf(t_enemy *current, t_data *data);
void				update_zombie(t_enemy *current, t_data *data);

// move
void				move_enemies(t_data *data);

// combat
void				combat_enemies(t_data *data);
void				enemy_take_damage(t_data *data, t_enemy *enemy);

// raycast
bool				can_see_player(t_data *data, t_enemy *enemy);

// utils
void				check_impact_on_enemy(t_data *data, t_enemy *enemy);
bool				is_on_screen(t_enemy *enemy);
bool				is_enemy_blocking(t_data *data, int map_x, int map_y);

#endif