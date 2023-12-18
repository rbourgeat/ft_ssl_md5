/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:02:12 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/18 15:47:51 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s + i != NULL && s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

int	    ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*ptrstr;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ptrstr = str;
	while (size + 1)
	{
		*ptrstr = 0;
		ptrstr++;
		size--;
	}
	return (str);
}

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptrdst;

	ptrdst = dst;
	while (*src)
		*(ptrdst++) = *(src++);
	*ptrdst = *src;
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptrs1;

	ptrs1 = s1;
	while (*ptrs1)
		ptrs1++;
	ptrs1 = ft_strcpy(ptrs1, s2);
	return (s1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	return (ft_strcat(ft_strcat(join, s1), s2));
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_strcpy(dup, s1));
}

void	ft_putstr(char const *s)
{
	size_t	size;

	if (!s)
		return ;
	size = ft_strlen(s);
	write(1, s, size);
}

int		ft_getline(const int fd, char **line)
{
	char	buff[2];
	char	*dup;
	char	*tmp;
	int		ret;

	dup = ft_strnew(0);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[1] = 0;
		if (!ft_strcmp(buff, "\n"))
			break ;
		tmp = dup;
		dup = ft_strjoin(dup, buff);
		ft_strdel(&tmp);
	}
	*line = ft_strdup(dup);
	ft_strdel(&dup);
	return (ret);
}

size_t	ft_readfile(const int fd, char **buf)
{
	char	buff[1024];
	char	*dup;
	char	*tmp;
	int		ret;
	size_t	len;

	dup = ft_strnew(0);
	len = 0;
	while ((ret = read(fd, buff, 1023)) > 0)
	{
		len += ret;
		buff[ret] = 0;
		tmp = dup;
		dup = ft_strjoin(dup, buff);
		ft_strdel(&tmp);
	}
	*buf = ft_strdup(dup);
	ft_strdel(&dup);
	(*buf)[len] = 0;
	return (len);
}

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned	char			*str1;
	const	unsigned	char	*str2;

	str1 = (unsigned char *)destination;
	str2 = (unsigned char *)source;
	if (!size || destination == source)
		return (destination);
	while (size--)
		*str1++ = *str2++;
	return (destination);
}

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned	int		i;
	unsigned	char	*c;

	i = 0;
	c = (unsigned char *)pointer;
	while (i < count)
		c[i++] = (unsigned char)value;
	pointer = (void *)c;
	return (pointer);
}
