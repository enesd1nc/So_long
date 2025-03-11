/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:21:44 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 14:14:42 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"

void	find_player_pos(t_data *data, int *x, int *y)
{
	*y = 0;
	while (data->map[*y])
	{
		*x = 0;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	increment_move_counter(void)
{
	static int	g_move_count = 0;

	g_move_count++;
	printf("%d\n", g_move_count);
}

static int	init_game(t_data **data, char *map_path)
{
	*data = init_data();
	if (!*data)
		return (0);
	if (!setup_map(*data, map_path))
	{
		close_window(*data);
		return (0);
	}
	if (!load_textures(*data) || !setup_window(*data))
	{
		close_window(*data);
		return (0);
	}
	draw_map(*data);
	return (1);
}

static void	setup_game_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, handle_window_close, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		return_value;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
	{
		ft_printf("Error: Invalid map\n");
		return (1);
	}
	if (!init_game(&data, argv[1]))
		return (1);
	setup_game_hooks(data);
	mlx_loop(data->mlx);
	return_value = close_window(data);
	return (return_value);
}
