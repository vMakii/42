/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:06:40 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/19 21:36:37 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_ray
{
	t_coord_float	ray_dir;
	float			camera_x;
	t_coord_float	delta_dist;
	t_coord_float	step;
	t_coord_int		map;
	t_coord_float	side_dist;
	int				side;
	float			perp_wall_dist;
	t_coord_float	wall_hit;
	int				line_height;
	int				draw_start;
	int				draw_end;
	float			wall_x;
	int				tex_num;
	int				tex_x;
	float			tex_pos;
	float			tex_step;
	int				tex_y;
	int				hit;
	int				p;
	float			pos_z;
	float			row_distance;
	int				upper_wall_height;
	int				upper_draw_start;
	int				upper_draw_end;
	int				original_upper_draw_start;
	float			upper_step;
	float			skip_pixels;
	float			upper_tex_pos;
}					t_ray;

// ceiling
void				draw_ceiling_column(t_data *data, t_ray ray, int x,
						int ceiling_end);

// central ray
void				update_central_ray(t_data *data, t_ray *ray, int x);

// double wall
void				draw_double_wall(t_data *data, t_ray *ray, int x);

// floor
void				draw_floor_column(t_data *data, t_ray ray, int x,
						int floor_end);

// init ray
void				init_ray(t_data *data, t_ray *ray, int x);

// raycasting
void				perp_distance_to_wall(t_data *data, t_ray *ray);
void				get_wall_column(t_data *data, t_ray *ray);
void				raycasting(t_data *data);

// wall
void				get_texture_column(t_ray *ray, char c);
void				draw_wall_texture(t_data *data, t_ray *ray, int x,
						t_image texture);
void				draw_wall(t_data *data, t_ray *ray, int x);

#endif