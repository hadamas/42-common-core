/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:13:53 by ahadama-          #+#    #+#             */
/*   Updated: 2024/01/30 14:24:53 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char c)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if ((c >> count) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		count--;
		usleep(350);
	}
}

int	ft_check_arg(char *pid, char *msg)
{
	if (!msg)
		return (-1);
	while (*pid)
	{
		if (!ft_isdigit(*pid))
		{
			ft_putstr("Error: PID can only contain numbers!");
			return (-1);
		}
		pid++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		if (ft_check_arg(av[1], av[2]) == -1)
			return (0);
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_send_bits(pid, av[2][i]);
			i++;
		}
	}
	else
		ft_putstr("Error!\nDefault Command Writing: ./client PID 'MESSAGE'\n");
	return (0);
}
