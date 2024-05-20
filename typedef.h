/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:32:34 by dongjle2          #+#    #+#             */
/*   Updated: 2024/05/19 22:01:43 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_complex
{
	double real;
	double imagine;
}	t_complex;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		zoom;
}	t_fractol;

#endif