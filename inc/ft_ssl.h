/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:55:54 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/18 12:40:15 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_cmd
{
	char		*name;
	int			(*exec)(int, char **);
}				t_cmd;

int md5(int ac, char **av);
int sha256(int ac, char **av);

// libft.c
void ft_putstr_fd(char *s, int fd);
int	ft_strlen(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_getline(const int fd, char **line);
void ft_strdel(char **as);

#endif