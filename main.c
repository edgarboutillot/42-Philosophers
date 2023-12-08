/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:52:33 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/17 12:16:05 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static int	ft_check_params(t_data *data, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;

	data.max_ate = 0;
	data.stop_condition = 0;
	if (argc < 5 || argc > 6)
		return (print_error("Invalid number of args\n"));
	if (!ft_check_params(&data, argc, argv))
		return (print_error("Incorrect parameters.\n"));
	if (!ft_init(&data))
		return (print_error("Init error.\n"));
	if (!start_threads(&data))
		return (print_error("Threads error.\n"));
	return (0);
}

static int	ft_check_params(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->eat_count_max = ft_atoi(argv[5]);
	else
		data->eat_count_max = 0;
	if (data->count < 1 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->eat_count_max < 0)
		return (0);
	return (1);
}
