/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:07:13 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/06 00:53:53 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1);
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My Fractol");
    if (!win_ptr)
        return (1);

    mlx_loop(mlx_ptr);
    
    return (0);
}
