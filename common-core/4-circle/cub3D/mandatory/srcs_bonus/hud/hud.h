/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:05:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 11:07:53 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

typedef struct s_minimap
{
	t_coord_int		here;
	t_coord_int		player;
	t_coord_int		start;
	t_coord_int		end;
	t_coord_int		offset;
	t_coord_int		pos;
	t_coord_float	pixel_offset;
	int				radius;
}					t_minimap;

typedef struct s_enemies_on_map
{
	t_coord_float	relative_pos;
	t_coord_int		map_pos;
	t_rect			rect;
}					t_enemies_on_map;

void				render_health_bar(t_data *data);
void				render_hud(t_data *data);
void				draw_enemies_on_map(t_data *data, t_rect *player_rect);
void				draw_player_on_map(t_data *data, t_rect *player_rect);
void				render_minimap(t_data *data);

#endif