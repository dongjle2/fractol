/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:23:03 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/11 17:29:37 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"

void	display_error(void)
{
	write(STDOUT_FILENO, RED, 5);
	write(STDOUT_FILENO, "invalid input\n", 14);
	write(STDOUT_FILENO, RESET, 5);
	write(STDOUT_FILENO, GREEN, 5);
	write(STDOUT_FILENO, "usage: ", 5);
	write(STDOUT_FILENO, "./fractol [type of fractal] [options]\n", 39);
	write(STDOUT_FILENO, "     type of fractal: 1 -> mandelbrot set\n", 43);
	write(STDOUT_FILENO, "     type of fractal: 2 -> julia set\n", 38);
	write(STDOUT_FILENO, "     type of fractal: 3 -> tricorn\n", 36);
	write(STDOUT_FILENO, "     example: ./fractol 1\n", 27);
	write(STDOUT_FILENO, "     example: ./fractol 2 -0.4 -0.6\n", 37);
	write(STDOUT_FILENO, "     example: ./fractol 3\n", 27);
	write(STDOUT_FILENO, RESET, 5);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

int	valid_chrs(const char *str)
{
	size_t	i;
	size_t	len;
	int		dot_found;

	i = 0;
	dot_found = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (i < len && (('0' <= str[i] && str[i] <= '9')))
			;
		else if (str[i] == '.')
			dot_found++;
		i++;
	}
	if (i != len)
		return (1);
	if (1 < dot_found)
		return (1);
	return (0);
}

int	is_valid_str(const char *str)
{
	char	dot_found;
	char	digit_found;

	dot_found = 0;
	digit_found = 0;
	if (valid_chrs(str) == 1)
		return (1);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == 0)
		return (1);
	while (*str)
	{
		if (*str == '.')
			dot_found = 1;
		else if ('0' <= *str && *str <= '9')
			digit_found = 1;
		else
			return (1);
		str++;
	}
	if (digit_found == 0)
		return (1);
	return (0);
}