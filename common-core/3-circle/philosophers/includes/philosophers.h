/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:35 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/02 14:39:05 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct s_data;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}					t_state;

typedef struct s_philo
{
	int				id;
	int				num_meals;
	int				last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				dead;
	pthread_mutex_t	*dead_lock;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	t_philo			*philos;
}					t_data;

// init
void				*ft_admin(void *ptr);
void				*ft_routine(void *ptr);
// utils
void				ft_error(char *str);
void				ft_free(t_data *data);
int					ft_isnum(char *str);
int					ft_strlen(char *str);
long				ft_atol(const char *str);
size_t				ft_get_time(void);
void				ft_usleep(size_t time);

#endif