/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:56 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/10 02:41:47 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_mlx(t_data *img)
{
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
double map(int value, int min_screen, int max_screen, double min_set, double max_set)
{
    return min_set + (double)(value - min_screen) * (max_set - min_set) / (max_screen - min_screen);
}
int mandelbrot(double real, double imag)
{
    double z_real = 0;
    double z_imag = 0;
    int iter = 0;

    while ((z_real * z_real + z_imag * z_imag < 4) && (iter < MAX_ITER))
    {
        double temp = z_real * z_real - z_imag * z_imag + real;
        z_imag = 2 * z_real * z_imag + imag;
        z_real = temp;
        iter++;
    }
    return iter; // Number of iterations before escaping
}
void draw_mandelbrot(t_data *data)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double real = map(x, 0, WIDTH, -2.0, 2.0);
            double imag = map(y, 0, HEIGHT, -2.0, 2.0);
            int iter = mandelbrot(real, imag);
            
            int color = (iter == MAX_ITER) ? 0x000000 : iter * 0x0F0F0F;
            my_mlx_pixel_put(data, x, y, color);
        }
    }
}
int main()
{
    t_data img;

    init_mlx(&img);
    draw_mandelbrot(&img);

    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_loop(img.mlx);
    
    return 0;
}
