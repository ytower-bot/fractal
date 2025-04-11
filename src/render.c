/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:55:20 by yfaustin          #+#    #+#             */
/*   Updated: 2025/04/11 14:55:27 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

void	render_fractal(t_fractal *f)
{
	int			i;
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x - WIDTH / 2.0) / (0.5 * WIDTH * f->zoom) + f->offset_x;
			c.im = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * f->zoom) + f->offset_y;
			if (f->type == 1)
				i = mandelbrot(c);
			else
				i = julia(c, f->julia);
			my_mlx_pixel_put(f, x, y, get_color(i));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
