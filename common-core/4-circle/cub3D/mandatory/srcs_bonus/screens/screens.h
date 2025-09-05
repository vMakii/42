/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screens.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:36:19 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/22 12:21:04 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREENS_H
# define SCREENS_H
# include "cub3d_bonus.h"

typedef enum state
{
	START,
	EXIT,
}			t_state;

typedef struct s_starting_screen
{
	t_state	state;
	bool	start;
}			t_starting_screen;

void		starting_screen(t_data *data);
void		load_screens(t_data *data);
void		destroy_screens(t_data *data);

#endif