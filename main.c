#include "MLX42/MLX42.h"
#include "fractol.h"
#include "typedef.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	param = NULL;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	// Simple up or down detection.
	if (0 < ydelta || 0 < xdelta)	//down
	{
		// fractol->zoom *= 0.9;
		printf("zoom: %f\n", fractol->zoom);
	}
	else if (ydelta < 0)	//up
		puts("Down!");
	// for (int x = 0; x < (int)fractol->g_img->width; x++)
	// 	for(int y= 0; y < (int)fractol->g_img->height; y++)
	// 		manipulate_pixels(fractol, x, y);
}

void	hook(void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	mlx_scroll_hook(fractol->mlx, &my_scrollhook, NULL);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_P))
		mlx_delete_image(fractol->mlx, fractol->g_img);
	// for (int x = 0; x < (int)fractol->g_img->width; x++)
	// 	for(int y= 0; y < (int)fractol->g_img->height; y++)
	// 		manipulate_pixels(fractol, x, y);
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
	fractol->zoom = 1;
	mlx_image_to_window(fractol->mlx, fractol->g_img, 30, 30);
	mlx_key_hook(fractol->mlx, &my_keyhook, NULL);
	mlx_loop_hoAok(fractol->mlx, &hook, (void *)fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	return (EXIT_SUCCESS);
}
