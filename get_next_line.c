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
	const char	*temp_left = NULL;
	char	*temp_read;
	char	*result;
	int		read_size;
	int		i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	temp_read = (char *) malloc(BUFFER_SIZE);
	if (!temp_read)
		return (NULL);
	read_size = read(fd, temp_read, BUFFER_SIZE);
	i = -1;
	while (++i < read_size)
	{
		if (*(temp_read + i) == '\n')
		{
			result = (char *) malloc(i);
			ft_memmove(result, temp_read, i);
			break ;
		}
	}
	if (*(temp_read + i) == '\n')
		result = (char *) malloc(i);
	else
		result = (char *) malloc(i);
	ft_memmove(result, temp_read, i);
	free(temp_read);
	return (result);
}
