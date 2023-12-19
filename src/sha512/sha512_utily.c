/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_utily.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:47:22 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 14:47:22 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sha512.h"
// #define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
// #define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

uint64_t	sha512_ch(uint64_t x, uint64_t y, uint64_t z)
{
	return ((x & y) ^ (~x & z));
}

uint64_t	sha512_maj(uint64_t x, uint64_t y, uint64_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}
