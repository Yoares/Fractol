/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:56 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/11 16:34:23 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_to_complex(int x, int y, double *real, double *imag, t_data *data)
{
	*real = (data->min_real) + ((double)x / WIDTH) * (data->max_real - data->min_real);
	*imag = (data->min_imag) + ((double)y / HEIGHT) * (data->max_imag - data->min_imag);
}

int	mandelbrot_itiration(double real, double imag, int max_iter)
{
	double	z_real;
	double	z_imag;
	double	tmp;
	int		iter;

	z_real = 0;
	z_imag = 0;
	tmp = 0;
	iter = 0;
	while ((z_real * z_real + z_imag * z_imag < 4) && (iter < max_iter))
	{
		tmp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = tmp;
		iter++;
	}
	return (iter);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot(t_data *data)
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
			color = get_color(iter, data->max_iter);
			my_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
