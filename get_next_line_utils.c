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

