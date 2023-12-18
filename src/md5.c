/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:06 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/18 16:21:19 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/md5.h"

t_flags	g_md5_flags[5] =
{
	{ MD5_P, 'p' },
	{ MD5_Q, 'q' },
	{ MD5_R, 'r' },
	{ MD5_S, 's' },
	{ 0, 0 },
};

int	md5_usage(char *msg, char arg, int errnum)
{
	ft_putstr_fd("md5: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nUsage: md5 [-pqrtx] [-s string] [files ...]\n", 2);
	return (errnum);
}

int	md5_search_flag(uint8_t *flags, char arg)
{
	int		idx;

	idx = 0;
	while (g_md5_flags[idx].flag)
	{
		if (arg == g_md5_flags[idx].c)
		{
			*flags |= g_md5_flags[idx].flag;
			return (0);
		}
		idx++;
	}
	return (1);
}

int	md5_print_error(char *msg, char *arg, int errnum)
{
	ft_putstr_fd("md5: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
    ft_putchar_fd('\n', 2);
	return (errnum);
}

int md5_manage_stdin(uint8_t *flags, uint8_t echo)
{
	size_t	size;
	char	*buff;
	char	tmp;

	*flags |= MD5_INPUT;
	size = ft_readfile(0, &buff);
	if (echo)
	{
		tmp = buff[size - 1];
		buff[size - 1] = 0;
		ft_putstr(buff);
        ft_putchar('\n');
		*flags ^= MD5_P;
		buff[size - 1] = tmp;
	}
	char *result = md5_digest(buff, size);
    if (result == NULL) {
        ft_strdel(&buff);
        return 1;
    }
    while (*result != '\0') {
        ft_putchar(*result);
        result++;
    }
    ft_putchar('\n');
	ft_strdel(&buff);
	return (0);
}

int md5_manage_string(uint8_t *flags, char *str, char *c, size_t len)
{
	*flags |= MD5_INPUT;
	if (!((*flags & MD5_R) || (*flags & MD5_Q)))
	{
		ft_putstr("MD5 (");
		*flags & MD5_END ? 0 : ft_putstr("\"");
		ft_putstr(str);
		*flags & MD5_END ? 0 : ft_putstr("\"");
		ft_putstr(") = ");
	}
	ft_putstr(md5_digest(c, len));
	if ((*flags & MD5_R) && !(*flags & MD5_Q))
	{
		*flags & MD5_END ? ft_putstr(" ") : ft_putstr(" \"");
		ft_putstr(str);
		*flags & MD5_END ? 0 : ft_putstr("\"");
	}
	*flags ^= MD5_S;
	return (0);
}

int md5_manage_file(uint8_t *flags, char *filename)
{
	struct stat	st_stat;
	char		*content;
	int			fd;

	*flags |= MD5_END;
	fd = open(filename, O_RDONLY);
	if (fd == -1 && errno == EACCES)
		return (md5_print_error(": Permission denied", filename, -1));
	else if (fd == -1)
		return (md5_print_error(": No such file or directory", filename, -2));
	else if (fstat(fd, &st_stat) == -1)
		return (md5_print_error(": Permission denied", filename, -1));
	else if (S_ISDIR(st_stat.st_mode))
		return (md5_print_error(": Is a directory", filename, -3));
	content = ft_strnew(st_stat.st_size);
	read(fd, content, st_stat.st_size);
	close(fd);
	*flags |= MD5_S;
	md5_manage_string(flags, filename, content, st_stat.st_size);
	ft_strdel(&content);
	return (0);
}

int	md5_manage_args(uint8_t *flags, char *arg)
{
	if (!(*flags & MD5_END) && *arg == '-')
	{
		while (*(++arg))
		{
			if (*flags & MD5_S)
			{
				md5_manage_string(flags, arg, arg, ft_strlen(arg));
				break ;
			}
			if (md5_search_flag(flags, *arg))
				return (md5_usage("illegal option", *arg, 1));
			if (*flags & MD5_P)
				md5_manage_stdin(flags, 1);
		}
	}
	else if (*flags & MD5_S)
		md5_manage_string(flags, arg, arg, ft_strlen(arg));
	else
		md5_manage_file(flags, arg);
	return (0);
}

int md5(int ac, char **av) {
    int		idx;
	uint8_t	flags;
	char	*arg;

	idx = 0;
	if (!ac)
		return (md5_manage_stdin(&flags, 0));
	while (idx < ac)
	{
		arg = av[idx];
		if (md5_manage_args(&flags, arg))
			return (1);
		idx++;
	}
	if (flags & MD5_S)
		return (md5_usage("option requires an argument", 's', 1));
	if (!(flags & MD5_INPUT))
		return (md5_manage_stdin(&flags, 0));
	return (0);
}