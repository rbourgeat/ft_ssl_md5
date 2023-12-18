/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:55:54 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/18 15:48:01 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct	s_cmd
{
	char		*name;
	int			(*exec)(int, char **);
}				t_cmd;

typedef struct	s_flags
{
	uint8_t		flag;
	char		c;
}				t_flags;

int md5(int ac, char **av);
int sha256(int ac, char **av);

// libft.c
void ft_putchar(char c);
void ft_putchar_fd(char c, int fd);
char *ft_strnew(size_t size);
void ft_putstr(char const *s);
void ft_putstr_fd(char *s, int fd);
int	ft_strlen(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_getline(const int fd, char **line);
void ft_strdel(char **as);
size_t ft_readfile(const int fd, char **buf);
void *ft_memcpy(void *destination, const void *source, size_t size);
void *ft_memset(void *pointer, int value, size_t count);

#endif