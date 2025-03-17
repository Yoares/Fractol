/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:08:12 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/10 02:38:18 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include "minilibx-linux/mlx.h"



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
}	t_data;

#endif