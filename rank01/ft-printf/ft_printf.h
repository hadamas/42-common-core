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

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_printf(const char	*format, ...);
int		ft_format(int n, va_list ap);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long long n, int c);
#endif
