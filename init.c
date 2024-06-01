/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:08:04 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/02 00:21:07 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "typedef.h"
#include <stdlib.h>

void	init_fractol(t_fractol	*fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->g_img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->x_max = X_MAX;
	fractol->x_min = X_MIN;
	fractol->y_max = Y_MAX;
	fractol->y_min = Y_MIN;
	if (fractol->type == '1')
		init_mandelbrot(fractol);
	fractol->left_right = 0;
	fractol->up_down = 0;
	fractol->zoom = 1;
	fractol->update = 1;
}

void	config_mandel(\
		t_fractol *fractol, t_linear_map *v, t_complex *z, t_complex *c)
{
	z->real = 0;
	z->imagine = 0;
	c->real = v->shifed_x * fractol->zoom + fractol->left_right;
	c->imagine = v->shifed_y * fractol->zoom + fractol->up_down;
}

void	config_julia(\
		t_fractol *fractol, t_linear_map *v, t_complex *z, t_complex *c)
{
	c->real = fractol->julia.c.real;
	c->imagine = fractol->julia.c.imagine;
	z->real = v->shifed_x * fractol->zoom + fractol->left_right;
	z->imagine = v->shifed_y * fractol->zoom + fractol->up_down;
}

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->x_max = 1;
	fractol->x_min = -2;
	fractol->y_max = 1.12;
	fractol->y_min = -1.12;
	fractol->num_iter = 1000;
}