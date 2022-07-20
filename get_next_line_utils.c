/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:17:50 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/19 17:17:51 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	while (*(s + ++i) != 0);
	return (i);
}

char	*ft_join_n_free(char *s1, char *s2)
{
	char	*dst;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (NULL);
	ft_memmove(dst, s1, s1_len);
	ft_memmove(dst + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, int len)
{
	int	i;

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
