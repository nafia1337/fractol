/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafia <bnafia@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:26:02 by bnafia            #+#    #+#             */
/*   Updated: 2025/03/21 13:44:14 by bnafia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

double	*linespace(double xmin, double xmax, int width)
{
	double	*x;
	double	step;
	int		i;

	x = (double *)malloc(width * sizeof(double));
	if (NULL == x)
		exit(0);
	step = (((double)xmax - xmin) / ((double)width - 1));
	i = 0;
	while (i < width)
	{
		if (i == 0)
			x[i] = xmin;
		else
			x[i] = x[i - 1] + step;
		i++;
	}
	return (x);
}

void	get_float_number(char *str_float, double *converted_nb, \
double rest_float_nb, int *sign)
{
	int	counter;
	int	is_float;

	counter = 0;
	is_float = 0;
	while (*str_float)
	{
		if (*str_float == '-')
			*sign = *sign * -1;
		else if (*str_float == '.')
			is_float = 1;
		else if (!is_float)
			*converted_nb = *converted_nb * 10 + (*str_float - '0');
		else
		{
			rest_float_nb = rest_float_nb * 10 + (*str_float - '0');
			counter++;
		}
		str_float++;
	}
	rest_float_nb = rest_float_nb / (pow(10, counter));
	*converted_nb = *converted_nb + rest_float_nb;
}

double	converttofloat(char *str_float)
{
	double	converted_number;
	int		sign;
	double	rest_float_nb;

	converted_number = 0;
	sign = 1;
	rest_float_nb = 0;
	get_float_number(str_float, &converted_number, rest_float_nb, &sign);
	return (converted_number * sign);
}

int	isdigit_str(char *str)
{
	int	i;
	int	is_float;

	i = 0;
	is_float = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			is_float = 1;
		else if (str[i] == '.' || str[i] == '-')
			is_float = 1;
		else
			is_float = 0;
		if (is_float == 0 && i != 0)
			return (is_float);
		i++;
	}
	return (is_float);
}
