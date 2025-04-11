/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:54:26 by yfaustin          #+#    #+#             */
/*   Updated: 2025/04/11 14:54:44 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_fractal *f, char **argv)
{
	f->type = 0;
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		f->type = 1;
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		f->type = 2;
		f->julia.re = ft_atof(argv[2]);
		f->julia.im = ft_atof(argv[3]);
	}
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
}

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit_error("mlx initialization failed\n");
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		exit_error("window creation failed\n");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		exit_error("image creation failed\n");
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
}
