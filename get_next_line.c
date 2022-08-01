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

void	ft_left_check(t_data *left, t_data *buff, int fd)
{
	if (left->str && left->size > 0)
	{
		buff->str = left->str;
		buff->size = left->size;
	}
	else
		buff->size = read(fd, buff->str, BUFFER_SIZE);
	left->str = NULL;
	left->size = 0;
	return ;
}

int	ft_check_buff(t_data *buff, t_data *result, t_data *left)
{
	ssize_t	i;

	i = 0;
	while (i < buff->size && *(buff->str + i) != '\n')
		++i;
	if (i < buff->size)
	{
		result->str = ft_data_join(result, buff->str, i + 1);
		left->str = ft_data_join(left, buff->str + i + 1, buff->size - i - 1);
		return (1);
	}
	else
		result->str = ft_data_join(result, buff->str, buff->size);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_data	left;
	t_data			result;
	t_data 			buff;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	result = (t_data){NULL, 0};
	buff.str = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff.str)
		return (NULL);
	ft_left_check(&left, &buff, fd);
	while (buff.size > 0)
	{
		if (ft_check_buff(&buff, &result, &left))
			break ;
		buff.size = read(fd, buff.str, BUFFER_SIZE);
	}
	free(buff.str);
	return (result.str);
}

