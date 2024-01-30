/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:08:26 by ahadama-          #+#    #+#             */
/*   Updated: 2024/01/30 14:17:47 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_minitalk_header(void);
void	ft_getchar(int bit);
void	ft_send_bits(int pid, char c);
int		ft_check_arg(char *pid, char *msg);
int		ft_isdigit(int c);
int		ft_atoi(char *str);

#endif
