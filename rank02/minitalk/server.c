/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:18:40 by ahadama-          #+#    #+#             */
/*   Updated: 2024/01/29 17:27:06 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minitalk.h"

void	ft_minitalk_header(void)
{

	ft_putstr("\033[95m███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗");
	ft_putstr("████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝");
	ft_putstr("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝");
	ft_putstr("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗");
	ft_putstr("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗");
	ft_putstr("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\033[97m");
	ft_putstr("\n\n");                                                            
}

void	ft_getchar(int bit)
{
	static	int	bits;
	static	char	c;

	bits = 0;
	c |= bit == SIGUSR2;
	if (++i == 8)
	{
		ft_putchar(c);
		c = 0;
		bits = 0;
	}
	else
		c << 1;
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
		ft_putstr("Error invalid format.\nDefault Command: ./server\n");
	else
	{
		ft_minitalk_header();
		ft_putstr("PID number: ");
		ft_putnbr(getpid());
		while (1)
		{
			signal(SIGUSR1, ft_getchar);
			signal(SIGUSR2, ft_getchar);
			pause();
		}
	}
	return (0);
}




