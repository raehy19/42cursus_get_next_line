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
	static t_left	left;
	char			*temp_read;
	char			*result;
	int				read_size;
	int				i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	result = NULL;
	if (left.size)
	{
		i = -1;
		while (++i < left.size && *(left.str + i) != '\n');
		if (i < left.size)
		{
			result = ft_join(NULL, left.str, 0, i);
			left.size = left.size - i;
			left.str = ft_join(NULL, left.str, i, left.size);
			return (result);
		}
		else
		{
			result = ft_join(NULL, left.str, 0, left.size);
			left.str = NULL;
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
			left.size = read_size - i;
			left.str = ft_join(NULL, temp_read, i, left.size);
			break ;
		}
		else
			result = ft_join(result, temp_read, 0, read_size);
	}
	free(temp_read);
	return (result);
}
