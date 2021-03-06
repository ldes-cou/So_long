/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:04:11 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/08/03 15:04:13 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_clean(t_data *d)
{
	if (d->mlx)
	{
		mlx_destroy_image(d->mlx, d->img.img);
		mlx_destroy_image(d->mlx, d->wall.img);
		mlx_destroy_image(d->mlx, d->floor.img);
		mlx_destroy_image(d->mlx, d->coin.img);
		mlx_destroy_image(d->mlx, d->player.img);
		mlx_destroy_image(d->mlx, d->exit.img);
		mlx_destroy_window(d->mlx, d->mlx_win);
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	if (d->map)
		free_map(d);
	exit(1);
	return (1);
}

int	free_map(t_data *d)
{
	int	i;

	i = 0;
	while (d->map[i])
	{
		free(d->map[i]);
		d->map[i] = NULL;
		i++;
	}
	free(d->map);
	return (0);
}
