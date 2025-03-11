/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:30:17 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 13:30:17 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *data)
{
	if (!data)
		return (0);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->collect)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->map)
		free_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	return (1);
}

static void	draw_map_row(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->map[y][x])
	{
		if (data->map[y][x] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->wall, x
				* TILE_SIZE, y * TILE_SIZE);
		else if (data->map[y][x] == '0')
			mlx_put_image_to_window(data->mlx, data->win, data->floor, x
				* TILE_SIZE, y * TILE_SIZE);
		else if (data->map[y][x] == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->player, x
				* TILE_SIZE, y * TILE_SIZE);
		else if (data->map[y][x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->collect, x
				* TILE_SIZE, y * TILE_SIZE);
		else if (data->map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->exit, x
				* TILE_SIZE, y * TILE_SIZE);
		x++;
	}
}

void	draw_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y])
	{
		draw_map_row(data, y);
		y++;
	}
}

int	load_textures(t_data *data)
{
	int	img_width;
	int	img_height;

	data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm",
			&img_width, &img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
			&img_width, &img_height);
	data->collect = mlx_xpm_file_to_image(data->mlx, "textures/collect.xpm",
			&img_width, &img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&img_width, &img_height);
	if (!data->wall || !data->floor || !data->player || !data->collect
		|| !data->exit)
		return (0);
	return (1);
}

int	setup_window(t_data *data)
{
	int	map_width;
	int	map_height;

	map_width = get_map_width(data->map);
	map_height = get_map_height(data->map);
	data->win = mlx_new_window(data->mlx, map_width * TILE_SIZE, map_height
			* TILE_SIZE, "So Long");
	if (!data->win)
		return (0);
	return (1);
}
