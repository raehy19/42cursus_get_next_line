/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:17:36 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/19 17:17:37 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp_left = NULL;
	char		*temp;
	char		*temp_read;
	char		*result;
	int			read_size;
	int			i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	result = NULL;
	if (temp_left)
	{
		read_size = ft_strlen(temp_left);
		i = -1;
		while (++i < read_size && *(temp_left+ i) != '\n');
		if (i < read_size)
		{
			result = ft_join(NULL, temp_left, 0, i);
			temp_left = ft_join_n_free(NULL, temp_left, i, read_size);
			return (result);
		}
		else
		{
			result = ft_join(NULL, temp_left, 0, read_size);
			free(temp_left);
			temp_left = NULL;
		}
	}
	temp_read = (char *) malloc(BUFFER_SIZE + 1);
	if (!temp_read)
		return (NULL);
	while ((read_size = read(fd, temp_read, BUFFER_SIZE)) > 0)
	{
		i = -1;
		while (++i < read_size && *(temp_read + i) != '\n');
		if (i < read_size)
		{
			result = ft_join(result, temp_read, 0, i);
			temp_left = ft_join(NULL, temp_read, i, read_size - i);
			break ;
		}
		else
			result = ft_join(result, temp_read, 0, read_size);
	}
	free(temp_read);
	return (result);
}
