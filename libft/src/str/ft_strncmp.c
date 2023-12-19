/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:26 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 13:34:26 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	size_t			i;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (*(tmp_s1 + i) != *(tmp_s2 + i))
			return (*(tmp_s1 + i) - *(tmp_s2 + i));
		if (*(tmp_s1 + i) == '\0')
			return (0);
	}
	return (0);
}
