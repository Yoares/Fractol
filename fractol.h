/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:08:12 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/23 00:09:40 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include "minilibx-linux/mlx.h"


#define DEFAULT_REAL -2.0
#define DEFAULT_IMAG 2.0
#define WIDTH  800
#define HEIGHT 600
#define SQUARE_SIZE 100
#define START_X  (WIDTH / 2 - SQUARE_SIZE / 2)
#define START_Y  (HEIGHT / 2 - SQUARE_SIZE / 2)
#define COLOR 0x00FF0000  // Red
#define MAX_ITER 50 // Maximum iterations for Mandelbrot calculation


typedef struct  s_data
{
	void	*mlx;
	void	*win;
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
    double  zoom;              // Zoom level
    double  offset_x;          // Horizontal shift
    double  offset_y;          // Vertical shift
    int     max_iter; 
    double  min_real;
    double  max_real;
    double  min_imag;
    double  max_imag;
}	t_data;

int	ft_strcmp(char *s1, char *s2);
t_data	init_mlx_window(void);
double ft_atof(const char *str);
void julia(t_data *data, double real, double imag);
void mandelbrot(t_data *data);
void error_message();
#endif