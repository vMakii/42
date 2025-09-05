/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:07:04 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/21 14:35:16 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

typedef struct s_sprite
{
	char				type;
	t_image				*image;
	t_coord_float		pos;
	t_coord_float		dir;
	t_coord_float		delta;
	float				distance;
	t_coord_float		transformed_pos;
	int					screen_x;
	int					height;
	int					width;
	t_coord_int			draw_start;
	t_coord_int			draw_end;
	int					tex_x;
	int					tex_y;
	int					tex_offset;
	int					d;
	float				offset;
	float				scale;
	bool				is_seeing_player;
	struct s_sprite		*next;
}						t_sprite;

void					render_sprites(t_data *data);
void					get_sprite_texture(t_data *data);
void					get_sprites_from_map(t_data *data);
void					sort_sprites(t_sprite **lst);
void					draw_sprites(t_data *data);
void					update_animated_sprites(t_data *data);

#endif