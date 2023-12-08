/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:22:28 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/17 12:11:53 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	value;

	i = 0;
	value = 0;
	neg = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		if (value > 922337203685477580 || (value == 922337203685477580))
			return (-1);
		else
			value = (value * 10) + nptr[i++] - '0';
	}
	if (neg)
		value = -value;
	return (value);
}

int	ft_isint(const char *nptr)
{
	int		i;
	int		neg;
	long	value;

	i = 0;
	value = 0;
	neg = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		if (value > 214748364 || (value == 214748364 && ((!neg && nptr[i]
						- '0' > 7) || (neg && nptr[i] - '0' > 8))))
			return (0);
		else
			value = (value * 10) + nptr[i++] - '0';
	}
	return (1);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				i;
	unsigned int	tmp_nbr;

	i = 0;
	ret = malloc(sizeof(*ret) * (ft_getlen(n) + 1));
	if (!ret)
		return (NULL);
	if (n < 0)
		tmp_nbr = -1 * n;
	else
		tmp_nbr = n;
	while (tmp_nbr != 0)
	{
		ret[i++] = (tmp_nbr % 10) + '0';
		tmp_nbr /= 10;
	}
	if (n == 0)
		ret[i++] = '0';
	if (n < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_reverse_str(ret);
	return (ret);
}
