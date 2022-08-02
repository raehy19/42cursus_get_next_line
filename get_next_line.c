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

void	ft_check_remain(t_data *remain, t_data *buff, int fd)
{
	if (remain->size > 0)
	{
		ft_str_move(buff->str, remain->str, remain->size);
		buff->size = remain->size;
		free(remain->str);
		remain->str = NULL;
		remain->size = 0;
	}
	else
		buff->size = read(fd, buff->str, BUFFER_SIZE);
	return ;
}

int	ft_check_buff(t_data *buff, t_data *result, t_data *remain)
{
	ssize_t	i;

	i = 0;
	while (i < buff->size && *(buff->str + i) != '\n')
		++i;
	if (i < buff->size)
	{
		buff->size = buff->size - i - 1;
		if (ft_data_join(remain, buff->str + i + 1, buff->size))
			return (-1);
		if (ft_data_join(result, buff->str, i + 1))
			return (-1);
		return (1);
	}
	else
		if (ft_data_join(result, buff->str, buff->size))
			return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_data	remain;
	t_data			result;
	t_data			buff;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	result = (t_data){NULL, 0};
	buff.str = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buff.str)
		return (NULL);
	ft_check_remain(&remain, &buff, fd);
	while (buff.size > 0)
	{
		if (ft_check_buff(&buff, &result, &remain))
			break ;
		buff.size = read(fd, buff.str, BUFFER_SIZE);
	}
	free(buff.str);
	return (result.str);
}
