/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:08:38 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 10:59:08 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_garbage
{
    void                *alloc;
    struct s_garbage    *next;
}                        t_garbage;

typedef struct s_sprite
{
	void		*n;
	void		*s;
	void		*e;
	void		*w;
}				t_sprite;

typedef struct s_map
{
	char		**tab;
	int			width;
	int			height;
	t_sprite	sprite;
}				t_map;

typedef struct s_data
{
	t_map		map;
}				t_data;

// Garbage Collector
void			*gc_malloc(size_t size, t_garbage **garbage_list);

// Parsing
bool			ft_parsing(t_data *data, char *map_file);
// Utils
void			ft_printerr(char *msg);

#endif