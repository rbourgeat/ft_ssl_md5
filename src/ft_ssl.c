/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:51 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 15:50:00 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"
#include <signal.h>

static char	*g_line;

void	_signal_handler(int signal)
{
	free(g_line);
	exit(signal);
}

static void	free_ssl(t_ssl	*ssl)
{
	ft_lstclear(&ssl->hash_list, free);
	free(ssl->hash_to_upper);
	free(ssl);
}

static void	mandatory_part(char **argv)
{
	t_ssl		*ssl;
	t_list		*tmp;
	t_hash		*hash;
	uint8_t		*result;

	ssl = parse(argv);
	if (!ssl)
		return ;
	tmp = ssl->hash_list;
	while (tmp)
	{
		hash = (t_hash *)tmp->content;
		if (hash->type == false)
			result = ssl->hash_func(hash->name, ft_strlen(hash->name));
		else
			result = read_file(ssl->hash_func, hash, ssl->hash);
		print_hash(ssl, hash, result);
		free(hash->name);
		tmp = tmp->next;
		free(result);
	}
	free_ssl(ssl);
}

static void	interactive_mode()
{
	int		r;
	char	**argv;

	signal(SIGINT, _signal_handler);
	signal(SIGQUIT, _signal_handler);
	signal(SIGTSTP, _signal_handler);
	while (1)
	{
		ft_putstr("FT_SSL > ");
		r = gnl(0, &g_line);
		if (r == 0 || g_line == NULL)
		{
			free(g_line);
			break;
		}
		if (!ft_strcmp(g_line, "exit"))
		{
			free(g_line);
			break;
		}
		if (g_line && g_line[0] != '\0')
		{
			argv = ft_split(g_line, ' ');
			free(g_line);
			mandatory_part(argv);
			ft_free_split(argv);
		}
		if (r < 0)
			ft_err("Error gnl: interactive_mode");
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		interactive_mode();
	else
		mandatory_part(argv + 1);
	return (0);
}
