/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:06:24 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/19 21:17:22 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_file
{
	char				*str;
	char				**tab;
	int					player_start[2];
	char				*map_name;
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					floor_color;
	int					ceiling_color;
}						t_file;

bool					check_texture(char **tab, char *id);
bool					check_colors(char **tab, char *id);
bool					is_valid_map_char(char c);
bool					check_data(t_data *data);
bool					check_map_nl(char *str);
bool					check_map(t_data *data);
bool					get_data(t_data *data);
bool					get_map(t_data *data);
bool					check_filename(char *filename, char *ext);
void					parsing(int argc, char **argv, t_data *data);
bool					read_file(char *filename, t_data *data);

#endif