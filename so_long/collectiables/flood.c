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

t_flood	ft_flood(char **map, t_pos player, int *visited, int height)
{
	t_flood	flood;

	flood.map = map;
	flood.x = player.x;
	flood.y = player.y;
	flood.visited = visited;
	flood.height = height;
	flood.check_collectibles = 1;
	return (flood);
}
