/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:45:17 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/06 13:16:39 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sisint(const char *s)
{
	int		slen;
	char	pre;

	if (s)
	{
		if (!ft_sisnum(s))
			return (0);
		pre = '\0';
		if (*s == '+' || *s == '-')
			pre = *s++;
		slen = ft_strlen(s);
		if (slen > 10 || slen < 1)
			return (0);
		if (slen == 10)
		{
			if ((!pre || pre == '+') && ft_strncmp(s, "2147483647", 10) > 0)
				return (0);
			if (pre == '-' && (ft_strncmp(s, "2147483648", 10) > 0))
				return (0);
		}
		return (1);
	}
	return (0);
}
