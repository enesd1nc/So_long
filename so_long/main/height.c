/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:45 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 13:58:45 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width])
		width++;
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

int	count_collectibles(t_data *data)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	handle_window_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}
