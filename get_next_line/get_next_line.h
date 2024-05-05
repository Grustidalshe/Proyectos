/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:03:56 by vtrubina          #+#    #+#             */
/*   Updated: 2024/02/22 02:00:20 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	read_line(char **remember, char **buffer, char **final_line, int fd);
char	*split_line(char **remember);
void	free_and_reset(void *var);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif
