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

char	*ft_is_nl_in_left(t_str *left, int i)
{
	char	*temp_left;
	char	*result;

	left->size = left->size - i;
	temp_left = (char *) malloc(sizeof(char) * (left->size));
	result = (char *) malloc(sizeof(char) * (i + 1));
	if (!temp_left || !result)
		return (NULL);
	ft_str_move(result, left->str, i);
	*(result + i) = '\0';
	ft_str_move(temp_left, left->str, left->size);
	free(left->str);
	left->str = temp_left;
	return (result);
}

void	ft_no_nl_in_left(t_str *result, t_str *left)
{
	result->str = left->str;
	result->size = left->size;
	left->str = NULL;
	left->size = 0;
}

char	*get_next_line(int fd)
{
	static t_str	left;
	static t_str	result;
	char			*buff;
	int				read_size;
	int				i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	result.str = NULL;
	result.size = 0;
	if (left.size)
	{
		i = -1;
		while (++i < left.size && *(left.str + i) != '\n');
		if (i < left.size)
			return (ft_is_nl_in_left(&left, i));
		else
			ft_no_nl_in_left(&result, &left);
	}
	buff = (char *) malloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		i = -1;
		while (++i < read_size && *(buff + i) != '\n');
		if (i < read_size)
		{
			ft_result_join(&result, buff, i);
			left.size = read_size - i;
			left.str = malloc(sizeof(char) * left.size);
			if (!left.str)
				return (NULL);
			ft_str_move(left.str, buff, left.size);
			break ;
		}
		else
			ft_result_join(&result, buff, read_size);
	}
	free(buff);
	return (ft_str_return(&result));
}
