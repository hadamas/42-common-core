/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:18 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/27 11:44:51 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printstr(const char *s);
int	ft_printnbr(int nb);
int	ft_printptr(unsigned long long ptr);
int	ft_print_unsint(unsigned int n);
int	ft_printhex(unsigned int n, const char c);
int	ft_printf(const char *s, ...);

#endif
