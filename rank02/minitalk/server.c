/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:18:40 by ahadama-          #+#    #+#             */
/*   Updated: 2024/01/30 14:44:10 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_header(void)
{
	ft_putstr("\
                               \n\
\033[95m███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n\
████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n\
██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\n\
██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\n\
██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n\
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\033[97m\n");
}

void	ft_getchar(int bit)
{
	static char	c;
	static int	bits;

	c |= bit == SIGUSR2;
	if (++bits == 8)
	{
		ft_putchar(c);
		c = 0;
		bits = 0;
	}
	else
		c = c << 1;
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
		ft_putstr("Error invalid format.\nDefault Command: ./server\n");
	else
	{
		ft_header();
		ft_putstr("PID number: ");
		ft_putnbr(getpid());
		ft_putchar('\n');
		while (1)
		{
			signal(SIGUSR1, ft_getchar);
			signal(SIGUSR2, ft_getchar);
			pause();
		}
	}
	return (0);
}
