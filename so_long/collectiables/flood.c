/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:57:03 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/20 01:57:03 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood(t_flood *flood, char **map, int width, int *visited)
{
	flood->map = map;
	flood->width = width;
	flood->visited = visited;
	flood->check_collectibles = 1;
}
