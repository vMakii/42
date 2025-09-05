/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:04:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/19 21:38:13 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOORS_H
# define DOORS_H

typedef struct s_door
{
	t_coord_int	pos;
	bool		is_open;
	float		open_amount;
	float		open_speed;
	int			sprite_index;
}				t_door;

typedef struct s_door_list
{
	t_door		*doors;
	int			count;
	int			capacity;
}				t_door_list;

// doors animation
void			update_doors(t_data *data);

// doors init
void			get_doors_from_map(t_data *data);

// doors interaction
void			interact_with_door(t_data *data);
bool			is_door_blocking(t_data *data, int map_x, int map_y);

// doors raycasting
int				get_door_texture_index(t_data *data, int map_x, int map_y);
bool			should_ray_continue_through_door(t_data *data, t_ray *ray,
					int x);

#endif