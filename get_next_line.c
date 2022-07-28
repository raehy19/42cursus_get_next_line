/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:17:36 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/27 21:50:33 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_left_check(t_str *left, char *buff, int fd)
{
	ssize_t	buff_size;

	if (left->size > 0)
	{
		buff = left->str;
		buff_size = left->size;
		left->str = NULL;
		left->size = 0;
	}
	else
		buff_size = read(fd, buff, BUFFER_SIZE);
	return (buff_size);
}

void	ft_find_nl(char *buff, t_str *result, t_str *left, )

char	*get_next_line(int fd)
{
	static t_str	left;
	t_str			result;
	char			*buff;
	ssize_t			buff_size;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	result = (t_str){NULL, 0};
	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	buff_size = ft_left_check(&left, buff, fd);
	while (buff_size > 0)
	{

		buff_size = read(fd, buff, BUFFER_SIZE);
	}
}

