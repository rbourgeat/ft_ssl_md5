/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:31:12 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 13:31:13 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tmp_c;
	unsigned char	*tmp_s;
	size_t			i;

	tmp_c = (unsigned char)c;
	tmp_s = (unsigned char *)s;
	i = -1;
	while (++i < n)
	{
		if (tmp_c == *tmp_s)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return ((void *)0);
}
