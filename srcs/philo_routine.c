/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:38:44 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/16 18:11:28 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	philo_print(char *msg, t_philo *philo, int unlock)
{
	char	*timestamp;

	timestamp = ft_itoa(get_time() - philo->data->start_time);
	pthread_mutex_lock(&philo->data->writing);
	if (!philo->data->stop_condition && !philo->data->max_ate)
		printf("%s %s %s\n", timestamp, philo->pos_str, msg);
	if (unlock)
		pthread_mutex_unlock(&philo->data->writing);
	free(timestamp);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->ffork]);
	philo_print("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->data->forks[philo->sfork]);
	philo_print("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->data->meal);
	philo_print("is eating", philo, UNLOCK);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->data->meal);
	new_sleep(philo->data->time_to_eat, philo->data);
	philo->ate_times++;
	pthread_mutex_unlock(&philo->data->forks[philo->sfork]);
	pthread_mutex_unlock(&philo->data->forks[philo->ffork]);
}

void	philo_dead(t_data *data, t_philo *philo)
{
	int	i;

	while (!data->max_ate)
	{
		i = -1;
		while (++i < data->count && !data->stop_condition)
		{
			pthread_mutex_lock(&data->meal);
			if ((int)(get_time() - philo[i].last_ate) >= data->time_to_die)
			{
				philo_print("died", &philo[i], LOCK);
				data->stop_condition = 1;
			}
			pthread_mutex_unlock(&data->meal);
		}
		if (data->stop_condition)
			break ;
		i = 0;
		while (data->eat_count_max && i < data->count
			&& philo[i].ate_times >= data->eat_count_max)
			i++;
		data->max_ate = (i == data->count);
	}
}
