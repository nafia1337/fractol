/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafia <bnafia@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:49:05 by bnafia            #+#    #+#             */
/*   Updated: 2025/03/21 13:44:41 by bnafia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <stddef.h>
# include <math.h>

double	*linespace(double xmin, double xmax, int width);
void	get_float_number(char *str_float, double *converted_nb, \
		double rest_float_nb, int *sign);
double	converttofloat(char *str_float);
int		isdigit_str(char *str);
#endif
