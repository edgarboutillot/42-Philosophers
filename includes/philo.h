/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:41:32 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/16 18:18:05 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Include ------------------------------------------------
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define UNLOCK 1
# define LOCK 0

// Typedef ------------------------------------------------
typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

// Struct -------------------------------------------------
struct					s_data
{
	int					count;
	int					eat_count_max;
	int					max_ate;
	int					stop_condition;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	unsigned long		start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing;
	pthread_mutex_t		meal;
	t_philo				*philos;
};

struct					s_philo
{
	int					pos;
	int					ate_times;
	int					ffork;
	int					sfork;
	char				*pos_str;
	unsigned long		last_ate;
	pthread_t			thread_id;
	struct s_data		*data;
};

// Initialization -----------------------------------------
int						ft_init(t_data *data);
// Thread  ------------------------------------------------
int						start_threads(t_data *data);
// Actions  ------------------------------------------------
void					philo_print(char *msg, t_philo *philo, int unlock);
void					philo_eat(t_philo *philo);
void					philo_dead(t_data *data, t_philo *philo);

// Utils ---------------------------------------------------
int						ft_atoi(const char *nptr);
int						ft_isint(const char *nptr);
char					*ft_itoa(int n);
unsigned long			get_time(void);
int						ft_strlen(char *str);
void					new_sleep(unsigned long duration, t_data *data);
int						ft_getlen(int n);
void					ft_reverse_str(char *str);
int						print_error(char *msg);

#endif
