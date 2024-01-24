/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:13:53 by ahadama-          #+#    #+#             */
/*   Updated: 2024/01/24 17:40:50 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits()

int	main(int ac, char *av[])
{
	int	i;
	int	pid;
	
	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_byte(pid, av[2][i]);
			i++;
		}
	}
	else
		ft_putstr("Error!\nDefault Command Writing: .client PID 'MESSAGE'\n");
	return (0);
}
