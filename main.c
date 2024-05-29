/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:39:41 by dongjle2          #+#    #+#             */
/*   Updated: 2024/05/30 00:54:47 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"
#include "typedef.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_P))
		mlx_delete_image(fractol->mlx, fractol->g_img);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->left_right += fractol->zoom * 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->left_right -= fractol->zoom * 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->up_down -= fractol->zoom * 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->up_down += fractol->zoom * 0.25;
	fractol->update = 1;
	rendering(fractol);
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	if (0 < ydelta || 0 < xdelta)	//down
	{
		fractol->zoom *= 0.9;
		// printf("%f\n", fractol->zoom);
	}
	else if (ydelta < 0)	//up
	{
		fractol->zoom *= 1.1;
		// printf("%f\n", fractol->zoom);
	}
	fractol->update = 1;
	rendering(fractol);
}

void	rendering(void *param)
{
	t_linear_map v;
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	if (fractol->update == 0)
		return ;
	for (int x = 0; x < (int)fractol->g_img->width; x++)
	{
		v.normalized_x = (double)x / WIDTH;
		v.shifed_x = fractol->x_min + (fractol->x_max - fractol->x_min) * v.normalized_x;
		for(int y= 0; y < (int)fractol->g_img->height; y++)
		{
			v.normalized_y = (double)y / HEIGHT;
			v.shifed_y = fractol->y_min + (fractol->y_max - fractol->y_min) * v.normalized_y;
			manipulate_pixels(fractol, &v, x, y);
		}
	}
	fractol->update = 0;
}

int32_t	main(int argc, char *argv[])
{
	t_fractol	*fractol;
	t_fractol	fractal;
	char x[15];

	if (argc != 1)
		return (0);
	if (argv[0])
		;
	// fractal.g_img = NULL;
	// fractal.mlx = NULL;
	write(1, "1 : mandelbroth set\n", 21);
	write(1, "2 : julia set\n", 15);
	write(1, "choose your option: ", 20);
	read(1, x, 15);
	if (x[0] == '1')
		fractol->type = 1;

	fractol = &fractal;
	init_fractol(fractol);
	mlx_loop_hook(fractol->mlx, rendering, (void *)fractol);
	mlx_image_to_window(fractol->mlx, fractol->g_img, 0, 0);
	mlx_scroll_hook(fractol->mlx, &my_scrollhook, (void *)fractol);
	mlx_key_hook(fractol->mlx, &my_keyhook, (void *)fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	return (EXIT_SUCCESS);
}
