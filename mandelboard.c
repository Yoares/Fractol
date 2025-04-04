/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:56 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/04 14:34:08 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_init_mande(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "mandelbrot");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->mlx, &data->bits_per_pixel, &data->line_length, &data->endian);	
	data->zoom = 1.0;
    data->offset_x = 0.0;
    data->offset_y = 0.0;
    data->max_iter = 50;
}
void pixel_to_complex(int x, int y, double *real, double *imag, t_data *data)
{
	*real = (data->min_real) + ((double)x / 800) * (data->max_real - data->min_real);
	*imag = (data->min_imag) + ((double)x / 800) * (data->max_imag - data->min_imag);
}

int	mandelbrot_itiration(double real, double imag, int max_iter)
{
	double	z_real = 0;
	double	z_imag = 0;
	double	tmp = 0;
	int	iter = 0;

	while((z_real * z_real + z_imag * z_imag < 4) && (iter < max_iter))
	{
		tmp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = tmp;
		iter++;
	}
	return iter;
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void mandelbrot(t_data *data)
{
    int (x), (y), (iter), (color);
    double (real), (imag);

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_to_complex(x, y, &real, &imag, data);
			iter = mandelbrot_itiration(real, imag, data->max_iter);
			if (iter == data->max_iter)
				color = 0x000000;
			else 
				color = iter * 0x0F0F0F;
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	
}


