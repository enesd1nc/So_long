/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:48:37 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 13:48:37 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "mlx.h"

static int	handle_exit(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E')
	{
		if (data->collectibles == 0)
		{
			increment_move_counter(data);
			ft_printf("%s\n", "Finish");
			mlx_loop_end(data->mlx);
			return (1);
		}
		ft_printf("collect them all ");
		ft_printf("remainder: %d\n", data->collectibles);
		return (1);
	}
	return (0);
}

static int	is_valid_move(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= get_map_width(data->map))
		return (0);
	if (new_y < 0 || new_y >= get_map_height(data->map))
		return (0);
	if (data->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	perform_movement(t_data *data, t_movement move)
{
	data->map[move.old_y][move.old_x] = '0';
	data->map[move.new_y][move.new_x] = 'P';
	draw_map(data);
	increment_move_counter(data);
}

static void	move_player(t_data *data, int new_x, int new_y)
{
	t_movement	move;
	int			current_x;
	int			current_y;

	find_player_pos(data, &current_x, &current_y);
	if (!is_valid_move(data, new_x, new_y))
		return ;
	move.old_x = current_x;
	move.old_y = current_y;
	move.new_x = new_x;
	move.new_y = new_y;
	if (handle_collectible(data, new_x, new_y))
	{
		perform_movement(data, move);
		return ;
	}
	if (handle_exit(data, new_x, new_y))
		return ;
	perform_movement(data, move);
}

int	key_press(int keycode, t_data *data)
{
	int	x;
	int	y;

	find_player_pos(data, &x, &y);
	if (keycode == 65307)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	else if (keycode == 119)
		move_player(data, x, y - 1);
	else if (keycode == 115)
		move_player(data, x, y + 1);
	else if (keycode == 97)
		move_player(data, x - 1, y);
	else if (keycode == 100)
		move_player(data, x + 1, y);
	return (0);
}
