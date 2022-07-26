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

	if (!s)
		return (0);
	i = -1;
	while (*(s + ++i) != 0);
	return (i);
}

char	*ft_join(char *s1, char *s2, int s2_start, int s2_len)
{
	char	*dst;
	int		s1_len;

	s1_len = ft_strlen(s1);
	dst = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (NULL);
	if (s1)
		ft_memmove(dst, s1, s1_len);
	if (s2)
		ft_memmove(dst + s1_len, s2 + s2_start, s2_len);
	*(dst + s1_len + s2_len) = '\0';
	return (dst);
}

char	*ft_join_n_free(char *s1, char *s2, int s2_start, int s2_len)
{
	char	*dst;
	int		s1_len;

	s1_len = ft_strlen(s1);
	dst = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (NULL);
	if (s1)
	{
		ft_memmove(dst, s1, s1_len);
		free(s2);
	}
	if (s2)
	{
		ft_memmove(dst + s1_len, s2 + s2_start, s2_len);
		free(s2);
	}
	*(dst + s1_len + s2_len) = '\0';
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
