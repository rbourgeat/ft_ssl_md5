/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:33 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 13:34:34 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (*tmp_s)
		tmp_s++;
	while (tmp_s >= s)
	{
		if (*tmp_s == c)
			return (tmp_s);
		tmp_s--;
	}
	return ((void *)0);
}
