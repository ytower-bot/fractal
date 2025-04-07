/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:22:30 by yfaustin          #+#    #+#             */
/*   Updated: 2025/04/07 16:13:22 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

typedef struct	s_data {
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc != 4)
		exit_error();

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, argv[3]);
	img.img = mlx_new_image(mlx, 80, 80);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 250);
	mlx_loop(mlx);
}

