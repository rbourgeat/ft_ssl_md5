/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:35:07 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 13:35:07 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (1)
	{
		len++;
		n /= 10;
		if (n == 0)
			break ;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	char		*tmp;
	int			len;

	nbr = n;
	len = ft_itoa_len(n);
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp)
		return ((void *)0);
	*(tmp + len) = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		*tmp = '-';
	}
	while (1)
	{
		*(tmp + --len) = nbr % 10 + '0';
		nbr /= 10;
		if (nbr == 0)
			break ;
	}
	return (tmp);
}
