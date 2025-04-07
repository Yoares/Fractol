/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:48:45 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/07 16:33:16 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void update_f(t_data *data)
{
    data->min_real = -2.0 / data->zoom + data->offset_x;
    data->max_real = 2.0 / data->zoom + data->offset_x;
    data->min_imag = -2.0 / data->zoom + data->offset_y;
    data->max_imag = 2.0 / data->zoom + data->offset_y;

    if (data->fractal_type == 0)
        mandelbrot(data);
    else if (data->fractal_type == 1)
        julia(data, data->c_real, data->c_img);

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	m_zoom(int button, int x, int y, t_data *data)
{
    double zoom_f;
    double mouse_x, mouse_y;
    double real_center, imag_center;

	if (button == 4)
		zoom_f = 1.1;
	else if (button == 5)
		zoom_f = 1.0 / 1.1;
	else
		return (0);
	data->zoom *= zoom_f;
	mouse_x = (double)x / WIDTH;
    mouse_y = (double)y / HEIGHT;

	real_center = data->min_real + mouse_x * (data->max_real - data->min_real);
	imag_center = data->min_imag + mouse_x * (data->max_imag - data->min_imag);
	data->min_real = real_center - (real_center - data->min_real) * zoom_f;
    data->max_real = real_center + (data->max_real - real_center) * zoom_f;
    data->min_imag = imag_center - (imag_center - data->min_imag) * zoom_f;
    data->max_imag = imag_center + (data->max_imag - imag_center) * zoom_f;
	update_f(data);
}
