/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:36:41 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/16 18:04:58 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

static int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->meal, NULL))
		return (1);
	if (pthread_mutex_init(&data->writing, NULL))
		return (1);
	return (0);
}

static int	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		data->philos[i].ate_times = 0;
		data->philos[i].pos = i + 1;
		data->philos[i].pos_str = ft_itoa(i + 1);
		if (!data->philos[i].pos_str)
			break ;
		data->philos[i].ffork = i;
		data->philos[i].sfork = (i + 1) % data->count;
		data->philos[i].data = data;
		i++;
	}
	if (i != data->count)
	{
		while (i >= 0)
		{
			free(data->philos[i].pos_str);
			i--;
		}
		return (1);
	}
	return (0);
}

int	ft_init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->count);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
	{
		free(data->philos);
		return (0);
	}
	if (ft_init_mutex(data))
	{
		free(data->philos);
		free(data->forks);
		return (0);
	}
	if (ft_init_philo(data))
	{
		free(data->philos);
		free(data->forks);
		return (0);
	}
	return (1);
}
