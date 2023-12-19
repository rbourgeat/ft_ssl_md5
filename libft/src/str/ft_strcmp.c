/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:33:11 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 13:33:11 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	size_t			i;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = -1;
	while (*(tmp_s1 + ++i))
		if (*(tmp_s1 + i) != *(tmp_s2 + i))
			break ;
	if (*(tmp_s1 + i) == '\0' && *(tmp_s2 + i) == '\0')
		return (0);
	return (*(tmp_s1 + i) - *(tmp_s2 + i));
}
