/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:17:50 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/27 21:55:54 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_str_move(char *dst, char *src, ssize_t len)
{
	ssize_t	i;

	if (dst > src)
	{
		i = len;
		while (--i > -1)
			*(((unsigned char *) dst) + i) = *(((unsigned char *) src) + i);
	}
	else
	{
		i = -1;
		while (++i < len)
			*(((unsigned char *) dst) + i) = *(((unsigned char *) src) + i);
	}
	return ;
}

int	ft_data_join(t_data *data, char *src, ssize_t len)
{
	char	*temp;

	if (len == 0)
		return (0);
	temp = (char *) malloc(sizeof(char) * (data->size + len + 1));
	if (!temp)
		return (-1);
	if (data->size > 0)
		ft_str_move(temp, data->str, data->size);
	if (len > 0)
		ft_str_move((temp + (data->size)), src, len);
	*(temp + data->size + len) = '\0';
	if (data->str)
		free(data->str);
	data->str = temp;
	data->size += len;
	return (0);
}
