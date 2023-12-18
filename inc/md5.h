/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:59:30 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/18 15:56:20 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"

# define MD5_P		0b000001
# define MD5_Q		0b000010
# define MD5_R		0b000100
# define MD5_S		0b001000
# define MD5_END	0b010000
# define MD5_INPUT	0b100000

# define S11 7
# define S12 12
# define S13 17
# define S14 22
# define S21 5
# define S22 9
# define S23 14
# define S24 20
# define S31 4
# define S32 11
# define S33 16
# define S34 23
# define S41 6
# define S42 10
# define S43 15
# define S44 21

typedef struct	s_md5_env
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	x[16];
}				t_md5_env;

typedef struct	s_md5_ctx
{
	uint32_t	state[4];
	uint32_t	count[2];
	uint8_t		buffer[64];
}				t_md5_ctx;

// md5_digest.c
uint32_t	md5_rotate_left(uint32_t x, uint32_t n);
char	*md5_digest(char *str, size_t len);
void	md5_decode(uint32_t *output, uint8_t *input, uint32_t len);

// md5_transform.c
void	md5_transform(uint32_t state[4], uint8_t block[64]);

#endif