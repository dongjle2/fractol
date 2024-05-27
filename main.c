/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:39:41 by dongjle2          #+#    #+#             */
/*   Updated: 2024/05/27 18:24:20 by dongjle2         ###   ########.fr       */
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
		fractol->left_right -= 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->left_right += 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->up_down -= 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->up_down += 0.25;
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
	rendering(fractol);
}

void	rendering(t_fractol *fractol)
{
	t_linear_map v;

	// v.scaled_x = 0;
	// v.scaled_y = 0;
	for (int x = 0; x < (int)fractol->g_img->width; x++)
	{
		v.normalized_x = (double)x / WIDTH;
		v.scaled_x = (fractol->x_max - fractol->x_min) * v.normalized_x;
		v.shifed_x = fractol->x_min + v.scaled_x;
		for(int y= 0; y < (int)fractol->g_img->height; y++)
		{
			v.normalized_y = (double)y / HEIGHT;
			v.scaled_y = (fractol->y_max - fractol->y_min) * v.normalized_y;
			v.shifed_y = fractol->y_min + v.scaled_y;
			manipulate_pixels(fractol, &v, x, y);
		}
	}
}

int32_t	main(void)
{
	t_fractol	*fractol;
	t_fractol	fractal;

	fractal.g_img = NULL;
	// fractal.mlx = NULL;
	//init_fractol()
	fractol = &fractal;
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->g_img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->x_max = X_MAX;
	fractol->x_min = X_MIN;
	fractol->y_max = Y_MAX;
	fractol->y_min = Y_MIN;
	// printf("scaling_x: %d\n", SCALING_X);
	fractol->left_right = 0;
	fractol->up_down = 0;
	fractol->zoom = 1;
	mlx_image_to_window(fractol->mlx, fractol->g_img, 0, 0);
	mlx_scroll_hook(fractol->mlx, &my_scrollhook, (void *)fractol);
	mlx_key_hook(fractol->mlx, &my_keyhook, (void *)fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	return (EXIT_SUCCESS);
}

