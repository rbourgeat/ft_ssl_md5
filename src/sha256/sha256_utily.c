/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_utily.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:47:06 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 14:47:06 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sha256.h"
// #define CH(x,y,z)		(((x) & (y)) ^ (~(x) & (z)))
// #define MAJ(x,y,z)		(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

uint32_t	sha256_ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (~x & z));
}

uint32_t	sha256_maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}
