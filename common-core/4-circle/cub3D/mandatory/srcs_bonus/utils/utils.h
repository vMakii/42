/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:07:19 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/03 12:48:09 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_garbage
{
	void				*alloc;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_rect
{
	t_coord_int			pos;
	float				width;
	float				height;
}						t_rect;

typedef struct s_fps
{
	float				current_time;
	float				total_time;
	float				frame_times[60];
	int					frame_index;
	int					frames_counted;
}						t_fps;

typedef struct s_time
{
	float				time;
	float				oldtime;
	float				frametime;
	int					fps;
}						t_time;

// colors
int						rgb_to_int(u_int8_t r, u_int8_t g, u_int8_t b);
int						*int_to_rgb(int color);
bool					is_pixel_transparent(unsigned int color);
void					apply_shadow(float distance, int *color, char type);

// draw forms
void					init_rect(t_rect *rect, float size, int start_x,
							int start_y);
int						draw_rect(t_image *img, t_rect rect, int color);
void					draw_line(t_image *img, t_coord_int start,
							t_coord_int end, int color);
void					put_img_to_frame(t_image *frame, t_image *img, int x,
							int y);

// exit
int						exit_success(t_data *data);
int						exit_failure(t_data *data, char *str);

// fps counter
float					get_time(void);
void					print_fps(t_data *data);
void					fps_counter(t_data *data);

// free
void					free_all(t_data *data);

// garbage collector
void					gc_free(t_garbage **gc_list);
void					*gc_add_malloc(void *ptr, t_garbage **gc_list);
char					**gc_add_tab(char **tab, t_garbage **gc_list);
void					*gc_malloc(size_t size, t_garbage **gc_list);

// print
void					print_data_map(t_data data);
void					print_sprites(t_data *data);
void					print_enemies(t_data *data);

// put pixel
int						get_texture_color(t_image *texture, int x, int y);
void					img_pix_put(t_image *img, int x, int y, int color);

// upscale image
void					upscale_img(t_data *data, t_image *sprite, int dest_x,
							int dest_y);

#endif