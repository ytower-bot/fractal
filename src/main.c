/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:22:30 by yfaustin          #+#    #+#             */
/*   Updated: 2025/04/11 14:54:17 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	check_args(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		exit_error("./fractol <type> [real_n] [imaginary_n]\n");
	if (ft_strncmp(av[1], "mandelbrot", 10) && ft_strncmp(av[1], "julia", 5))
		exit_error("invalid fractal type: use'mandelbrot' or 'julia'.\n");
	if (!ft_strncmp(av[1], "julia", 5) && ac != 4)
		exit_error("missing julia parameters: [julia_re] [julia_im]\n");
}

int	main(int ac, char **av)
{
	t_fractal	f;

	check_args(ac, av);
	init_fractal(&f, av);
	init_mlx(&f);
	render_fractal(&f);
	mlx_hook(f.win, 2, 1L << 0, key_hook, &f);
	mlx_hook(f.win, 4, 1L << 2, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}
