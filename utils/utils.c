/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:24:30 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/16 18:17:05 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void	new_sleep(unsigned long duration, t_data *data)
{
	unsigned long	start;

	start = get_time();
	while (!data->stop_condition)
	{
		if (get_time() - start >= duration)
			break ;
		usleep(data->count * 2);
	}
}

int	ft_getlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_reverse_str(char *str)
{
	int		begin;
	int		end;
	char	temp;

	begin = 0;
	end = ft_strlen(str) - 1;
	while (begin < end)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

int	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (0);
}
