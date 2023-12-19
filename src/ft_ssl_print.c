/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:33 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 16:21:15 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

void	ft_err(char *str)
{
	ft_putstr(str);
	exit (1);
}

static void	pre_print_hash(t_ssl *ssl, t_hash *hash)
{
	if (ssl->q == 0 && ssl->p == 0 && ssl->r == 0 && ssl->s == 0)
	{
		ft_putstr(ssl->hash_to_upper);
		ft_putstr("(");
		hash->type ? ft_putstr(hash->name) : ft_putstr("stdin");
		ft_putstr(")= ");
	}
	else if (ssl->q == 0 && hash->type == 0 && ssl->p == 1)
	{
		ft_putstr("(\"");
		write(1, hash->name, ft_strlen(hash->name) - 1);
		ft_putstr("\")= ");
	}
	else if (ssl->q == 0 && hash->type == 0 && \
			ft_lstsize(ssl->hash_list) == 1 && ssl->s == 0 && ssl->r == 0)
	{
		ft_putstr("(stdin)= ");
	}
	else if (ssl->q == 0 && hash->type == 0 && \
			ssl->s == 1 && ssl->r == 0)
	{
		ft_putstr(ssl->hash_to_upper);
		ft_putstr("(\"");
		ft_putstr(hash->name);
		ft_putstr("\")= ");
		ssl->s = 0;
	}
}

static void	after_print_hash(t_ssl *ssl, t_hash *hash)
{
	if (ssl->r == 1 && ssl->q == 0 && ssl->p == 0)
	{
		if (ssl->s == 0)
		{
			ft_putstr(" *");
			hash->type ? ft_putstr(hash->name) : ft_putstr("stdin");
		}
		else
		{
			ft_putstr(" \"");
			ft_putstr(hash->name);
			ft_putstr("\"");
			ssl->s = 0;
		}
	}
	ssl->p = 0;
	ft_putstr("\n");
}

static void	hex_print_hash(uint8_t *result, int len)
{
	char	buf[3];
	int		i;

	i = -1;
	buf[2] = '\0';
	i = -1;
	while (++i < len)
	{
		buf[0] = (result[i] >> 4) + '0';
		buf[1] = (result[i] & 0x0f) + '0';
		if (buf[0] > '9')
			buf[0] += 39;
		if (buf[1] > '9')
			buf[1] += 39;
		ft_putstr(buf);
	}
}

void	print_hash(t_ssl *ssl, t_hash *hash, uint8_t *result)
{
	if (!result)
		return ;
	if (ssl->q == 1 && ssl->p == 1)
		ft_putstr(hash->name);
	else
		pre_print_hash(ssl, hash);
	hex_print_hash(result, ssl->crypt_len);
	after_print_hash(ssl, hash);
}
