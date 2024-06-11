/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:08:04 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/11 18:36:32 by dongjle2         ###   ########.fr       */
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
	if (fractol->g_img == NULL)
		exit(EXIT_FAILURE);
	if (fractol->type == '1' || fractol->type == '3')
		init_mandelbrot(fractol);
	else
	{
		fractol->x_max = X_MAX;
		fractol->x_min = X_MIN;
		fractol->y_max = Y_MAX;
		fractol->y_min = Y_MIN;
		fractol->num_iter = 50000000;
	}
	fractol->update = 1;
	fractol->zoom = 1;
	fractol->color = 0;
	init_linear_map(&fractol->mapped);
}

void	config_mandel(\
		t_fractol *fractol, t_linear_map *v, t_complex *z, t_complex *c)
{
	z->real = 0;
	z->imagine = 0;
	c->real = v->shifed_x * fractol->zoom;
	c->imagine = v->shifed_y * fractol->zoom;
}

void	config_julia(\
		t_fractol *fractol, t_linear_map *v, t_complex *z, t_complex *c)
{
	c->real = fractol->julia.c.real;
	c->imagine = fractol->julia.c.imagine;
	z->real = v->shifed_x * fractol->zoom;
	z->imagine = v->shifed_y * fractol->zoom;
}

void	init_mandelbrot(t_fractol *fractol)
{
	if (fractol->type == '1')
	{
		fractol->x_max = 1;
		fractol->x_min = -2;
		fractol->y_max = 1.12;
		fractol->y_min = -1.12;
		fractol->num_iter = 500;
	}
	else
	{
		fractol->x_max = 1;
		fractol->x_min = -2;
		fractol->y_max = 1.5;
		fractol->y_min = -1.5;
		fractol->num_iter = 5000;
	}
}


void	init_linear_map(t_linear_map *v)
{

	v->shifed_x = 0;
	v->shifed_y = 0;
	v->normalized_x = 0;
	v->normalized_y = 0;
	v->scaled_x = 0;
	v->scaled_y = 0;
}