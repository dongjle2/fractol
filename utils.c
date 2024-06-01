/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:23:03 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/01 23:26:52 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_error(void)
{
	write(1, "invalid input\n", 15);
	write(1, "usage: ", 8);
	write(1, "./fractol [type of fractal] [options]\n", 39);
	write(1, "     type of fractal: 1 -> mandelbrot set\n", 43);
	write(1, "     type of fractal: 2 -> julia set\n", 38);
	write(1, "     example: ./fractol 1\n", 27);
	write(1, "     example: ./fractol 2 -0.4 -0.6\n", 37);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

int	is_valid_str(const char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len && (('0' <= str[++i] && str[i] <= '9') || str[i] == '.'))
		;
	if (i != len)
		return (1);
	return (0);
}
