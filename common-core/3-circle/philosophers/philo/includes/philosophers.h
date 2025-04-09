/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:35 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/09 14:06:54 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define KWHITE "\033[0;37m"
# define KRED "\033[0;31m"
# define KGRN "\033[0;32m"
# define KYEL "\033[0;33m"
# define KBLU "\033[0;34m"
# define KCYN "\033[0;36m"
# define KPUR "\033[0;35m"
# define KEND "\033[0m"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					num_meals;
	int					last_meal;
	pthread_t			thread;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_data		*data;
}						t_philo;

typedef struct s_data
{
	int					start_time;
	int					dead;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		*forks;
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_meals;
	t_philo				*philos;
}						t_data;

// init
int						check_args(char **av);
void					ft_init(t_data *data, int ac, char **av);
void					ft_init_forks(pthread_mutex_t *forks, int num_philo);
void					ft_init_philos(t_data *data);
void					ft_init_threads(t_data *data);
// threads
void					*ft_admin(void *ptr);
void					*ft_routine(void *ptr);
void					ft_eat(t_philo *philo);
void					ft_sleep(t_philo *philo);
void					ft_think(t_philo *philo);
// utils
void					ft_error(char *str);
void					ft_free(t_data *data);
void					ft_print(char *str, int id, t_philo *philo,
							char *color);
int						ft_isnum(char *str);
int						ft_strlen(char *str);
long					ft_atol(const char *str);
int						ft_get_time(void);
void					ft_usleep(int time);

#endif