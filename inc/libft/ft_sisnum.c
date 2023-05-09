/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:12:22 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/04 22:21:40 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sisnum(const char *s)
{
	int	ran;

	ran = 0;
	if (s)
	{
		if (*s == '+' || *s == '-')
			s++;
		while (*s)
		{
			ran = 1;
			if (!ft_isdigit(*s++))
				return (0);
		}
		if (ran)
			return (1);
	}
	return (0);
}
