/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:05:16 by vtrubina          #+#    #+#             */
/*   Updated: 2024/02/22 02:04:59 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	read_line(char **remember, char **buffer, char **final_line, int fd)
{
	size_t	read_result;
	char	*temp_result;

	read_result = 1;
	while (!ft_strchr(*remember, '\n') && read_result)
	{
		read_result = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[read_result] = '\0';
		temp_result = *remember;
		*remember = ft_strjoin(temp_result, *buffer);
		free(temp_result);
	}
	*final_line = split_line(remember);
	if (read_result == 0 && !(*remember)[0])
	{
		free(*remember);
		*remember = NULL;
		return (0);
	}
	if (!*final_line)
		free_and_reset(*final_line);
	return (read_result);
}

char	*split_line(char **remember)
{
	int		i;
	char	*remember_copy;
	char	*temp_remember;

	i = 0;
	while ((*remember)[i] != '\0')
	{
		if ((*remember)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (i == 0 || !*remember)
		return (NULL);
	temp_remember = *remember;
	remember_copy = ft_substr(temp_remember, 0, i);
	*remember = ft_strdup(&(*remember)[i]);
	free_and_reset(temp_remember);
	return (remember_copy);
}

void	free_and_reset(void *var)
{
	free(var);
	var = NULL;
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*remember;
	char		*buffer;
	char		*final_line;
	int			read_fd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free_and_reset(buffer);
		return (NULL);
	}
	if (!remember)
	{
		remember = ft_strdup("");
	}
	read_fd = read_line(&remember, &buffer, &final_line, fd);
	free_and_reset(buffer);
	if (read_fd <= 0 && !final_line)
		return (NULL);
	return (final_line);
}
