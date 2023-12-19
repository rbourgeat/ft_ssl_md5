/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_read_hash_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:39 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 15:37:57 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

char	*str_append(char *str_file, char *input_buff, size_t r, uint64_t *len)
{
	char		*tmp;

	tmp = (char *)malloc(*len + r);
	if (!str_file)
		ft_err("Error malloc: str_append");
	ft_memcpy(tmp, str_file, *len);
	free(str_file);
	ft_memcpy(tmp + *len, input_buff, r);
	*len += r;
	return (tmp);
}

static char	*read_to_str(int fd, uint64_t *len)
{
	char		*str_file;
	char		input_buff[1000];
	int			r;

	str_file = ft_strdup("");
	if (!str_file)
		ft_err("Error malloc: hash_file");
	while (1)
	{
		r = read(fd, input_buff, 1000);
		if (r == 0)
			break ;
		if (r < 0)
		{
			free (str_file);
			ft_err("Error read: hash_file");
		}
		str_file = str_append(str_file, input_buff, r, len);
	}
	return (str_file);
}

uint8_t	*read_file(uint8_t *(*hash_func)(const char *str, const uint64_t len), \
						t_hash *hash, char *hash_type)
{
	char		*str_file;
	uint64_t	len;
	int			fd;
	uint8_t		*result;

	fd = open(hash->name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("ft_ssl: ");
		ft_putstr(hash_type);
		ft_putstr(": ");
		ft_putstr(hash->name);
		ft_putstr(": No such file or directory\n");
		return (NULL);
	}
	len = 0;
	str_file = read_to_str(fd, &len);
	result = hash_func(str_file, len);
	free(str_file);
	close(fd);
	return (result);
}
