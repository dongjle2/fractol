/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:14:19 by dongjle2          #+#    #+#             */
/*   Updated: 2024/05/18 23:19:35 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "typedef.h"

#define WIDTH 800
#define HEIGHT 801
#define X_MAX 2
#define X_MIN -2
#define Y_MAX 2
#define Y_MIN -2
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define NUM_ITER 420

t_complex	sum_complex(t_complex x, t_complex y);
t_complex	square_complex(t_complex x);
void		manipulate_pixels(t_fractol *fractol, int x, int y);
#endif