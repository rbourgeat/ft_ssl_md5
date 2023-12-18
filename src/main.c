/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:55:10 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/18 14:59:53 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

t_cmd g_cmd[3] =
{
	{ "md5", &md5 },
	{ "sha256", &sha256 },
    { NULL, NULL },
};

int sha256(int ac, char **av) {
    (void)ac;
    (void)av;
    return 0;
}

int	ssl_usage(char *cmd)
{
	ft_putstr_fd("ft_ssl: Error: '", 2);
	ft_putstr_fd(cmd, 2);
    ft_putstr_fd("' is an invalid command.\n\n", 2);
    ft_putstr_fd("Commands:\n", 2);
    ft_putstr_fd("md5\n", 2);
    ft_putstr_fd("sha256\n", 2);
    ft_putstr_fd("\nFlags:\n", 2);
    ft_putstr_fd("-p -q -r -s\n", 2);
	return (0);
}

int	init_cmd(int ac, char **av)
{
	int		i;
	char	*cmd;

	i = 0;
	cmd = av[0];
	while (g_cmd[i].name)
	{
		if (!ft_strcmp(cmd, g_cmd[i].name))
			return (g_cmd[i].exec(ac - 1, av + 1));
		i++;
	}
	return (ssl_usage(cmd));
}

int	parse_stdin()
{
	char	*input;

	ft_putstr_fd("FT_SSL> ", 1);
	while (ft_getline(1, &input) > 0)
	{
		init_cmd(1, &input);
		ft_strdel(&input);
		ft_putstr_fd("FT_SSL> ", 1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int		ret;

    if (ac == 1) {
        ft_putstr_fd("usage: ft_ssl command [flags] [file/string]\n", 2);
        return (0);
    }
	if (ac < 2)
		return (parse_stdin());
	ret = init_cmd(ac - 1, av + 1);
	return (ret);
}