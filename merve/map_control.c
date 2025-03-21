/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:28:43 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/21 02:50:46 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	check_valid_chars(t_data *data, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'C' && data->map[i][j] != '0'
				&& data->map[i][j] != '1')
			{
				ft_printf("Error: Invalid map\n");
				close_window(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
