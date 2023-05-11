/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:35:17 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/11 13:12:51 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_argb(int a, int r, int g, int b)
{
	if (a < 0 || a > 255 || r < 0 || r > 255
		|| g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (a << 24 | r << 16 | g << 8 | b);
}

int	get_a(int argb)
{
	return ((argb >> 24) & 255);
}

int	get_r(int argb)
{
	return ((argb >> 16) & 255);
}

int	get_g(int argb)
{
	return ((argb >> 8) & 255);
}

int	get_b(int argb)
{
	return (argb & 255);
}
