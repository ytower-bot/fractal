/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:54:58 by yfaustin          #+#    #+#             */
/*   Updated: 2025/04/11 14:55:11 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == ESC)
		close_window(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	if (button == 4)
	{
		f->zoom *= 1.1;
		f->offset_x += (x - WIDTH / 2) / (WIDTH * f->zoom * 0.5);
		f->offset_y += (y - HEIGHT / 2) / (HEIGHT * f->zoom * 0.5);
	}
	else if (button == 5)
	{
		f->zoom /= 1.1;
		f->offset_x -= (x - WIDTH / 2) / (WIDTH * f->zoom * 0.5);
		f->offset_y -= (y - HEIGHT / 2) / (HEIGHT * f->zoom * 0.5);
	}
	render_fractal(f);
	return (0);
}

int	close_window(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
	return (0);
}
