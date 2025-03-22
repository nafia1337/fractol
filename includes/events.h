/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafia <bnafia@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:44:39 by bnafia            #+#    #+#             */
/*   Updated: 2025/03/21 09:47:26 by bnafia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		close_fract(t_vars *vars);
int		mouse_handlers(int button, t_vars *vars);
void	register_event(t_vars *vars);
int		key_handler(int keysym, t_vars *vars);
#endif
