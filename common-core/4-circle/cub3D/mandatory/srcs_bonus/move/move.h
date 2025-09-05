/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:06:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/22 12:20:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

typedef struct s_key
{
	int	key_a;
	int	key_d;
	int	key_w;
	int	key_s;
	int	key_left;
	int	key_right;
	int	key_up;
	int	key_down;
	int	key_e;
}		t_key;

void	player_move(t_data *data);
void	moving_angle(t_player *player, float angle);
void	calculate_new_position(t_data *data, t_coord_float *move);

#endif