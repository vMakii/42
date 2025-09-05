/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:06:07 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/19 21:37:40 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, t_data *data);
int	mouse_hook(t_data *data);
int	handle_mouse(int button, int x, int y, t_data *data);

#endif