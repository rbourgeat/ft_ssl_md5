/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:46:25 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 16:21:26 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/include/libft.h"

# include <stdint.h>
# include <stdio.h>

typedef enum		s_bool
{
	false,
	true
}					t_bool;

typedef struct		s_ssl
{
	char			*hash;
	char			*hash_to_upper;
	uint32_t		crypt_len;
	uint8_t			*(*hash_func)(const char *str, const uint64_t len);
	t_bool			p;
	t_bool			q;
	t_bool			r;
	t_bool			s;
	t_list			*hash_list;
}					t_ssl;

typedef struct		s_hash
{
	t_bool			type; // 0 - string, 1 - file
	char			*name;
}					t_hash;

uint8_t		*md5_main(const char *str, const uint64_t len);
uint8_t		*sha224_main(const char *str, const uint64_t len);
uint8_t		*sha256_main(const char *str, const uint64_t len);
uint8_t		*sha384_main(const char *str, const uint64_t len);
uint8_t		*sha512_main(const char *str, const uint64_t len);
t_ssl		*parse(char **argv);
int			parse_argv(char **argv, t_ssl *ssl);
void		parse_flag_p(t_ssl *ssl);
t_hash		*create_hash_node(char *name);
uint8_t		*read_file(uint8_t *(*hash_func)(const char *str, const uint64_t len), t_hash *hash, char *hash_type);
void		ft_err(char *str);
void		print_hash(t_ssl *ssl, t_hash *hash, uint8_t *result);

#endif
