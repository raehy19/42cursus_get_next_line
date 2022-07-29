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

char	*ft_str_move(char *dst, char *src, int len)
{
	int		i;

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
	return (dst);
}

char	*ft_data_join(t_data *data, char *str, ssize_t len)
{
	char	*temp;

	temp = (char *) malloc(sizeof(char) * (data->size + len + 1));
	if (!temp)
	{
		free(data->str);
		data->str = NULL;
		return (NULL);
	}
	if (data->size > 0)
		ft_str_move(temp, data->str, data->size);
	if (len > 0)
		ft_str_move(temp + data->size, str, len);
	*(temp + data->size + len) = '\0';
	if (data->str)
		free(data->str);
	data->str = temp;
	data->size += len;
	return (data->str);
}
