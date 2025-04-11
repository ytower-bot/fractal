/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:00:23 by yfaustin          #+#    #+#             */
/*   Updated: 2025/04/11 15:01:21 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define ESC 65307

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_complex	julia;
}	t_fractal;

// init
void	init_fractal(t_fractal *f, char **argv);
void	init_mlx(t_fractal *f);

// render
void	render_fractal(t_fractal *f);
void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color);
int		get_color(int iterations);

// fractals
int		mandelbrot(t_complex c);
int		julia(t_complex z, t_complex c);

// events
int		key_hook(int keycode, t_fractal *f);
int		mouse_hook(int button, int x, int y, t_fractal *f);
int		close_window(t_fractal *f);

// utils
void	exit_error(char *msg);
double	ft_atof(const char *str);

#endif
