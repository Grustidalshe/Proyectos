/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:07:42 by vtrubina          #+#    #+#             */
/*   Updated: 2023/11/23 20:12:29 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char const *s);
int	ft_direccion_u(unsigned int u, int i);
int	ft_mix(unsigned long int lin, char g);
int	ft_direccion_i_y_d(int d, int i);

#endif
