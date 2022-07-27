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



char	*ft_str_return(t_str *result)
{
	char	*dst;

	dst = (char *) malloc(sizeof(char) * (result->size + 1));
	if (!dst)
		return (NULL);
	ft_str_move(dst, result->str, result->size);
	free(result->str);
	result->str = NULL;
	result->size = 0;
	return (dst);
}

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


void	ft_result_join(t_str *result, char *str, int str_len)
{
	char	*dst;

	dst = (char *) malloc(sizeof(char) * (result->size + str_len));
	if (!dst)
		return ;
	ft_str_move(dst, result->str, result->size);
	ft_str_move(dst + result->size, str, str_len);
	free(result->str);
	result->str = dst;
	result->size += str_len;
	return ;
}
//
//char	*ft_join(char *s1, char *s2, int s2_start, int s2_len)
//{
//	char	*dst;
//	int		s1_len;
//
//	dst = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
//	if (!dst)
//		return (NULL);
//	if (s1)
//		ft_memmove(dst, s1, s1_len);
//	if (s2)
//		ft_memmove(dst + s1_len, s2 + s2_start, s2_len);
//	return (dst);
//}
//
//char	*ft_join_n_free(char *s1, char *s2, int s2_start, int s2_len)
//{
//	char	*dst;
//	int		s1_len;
//
//	s1_len = ft_strlen(s1);
//	dst = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
//	if (!dst)
//		return (NULL);
//	if (s1)
//	{
//		ft_memmove(dst, s1, s1_len);
//		free(s2);
//	}
//	if (s2)
//	{
//		ft_memmove(dst + s1_len, s2 + s2_start, s2_len);
//		free(s2);
//	}
//	return (dst);
//}
//
//void	*ft_memmove(void *dst, const void *src, int len)
//{
//	int	i;
//
//	if (dst > src)
//	{
//		i = len;
//		while (--i > -1)
//			*(((unsigned char *) dst) + i) = *(((unsigned char *) src) + i);
//	}
//	else
//	{
//		i = -1;
//		while (++i < len)
//			*(((unsigned char *) dst) + i) = *(((unsigned char *) src) + i);
//	}
//	return (dst);
//}
//int	ft_strlen(const char *s)
//{
//	int	i;
//
//	if (!s)
//		return (0);
//	i = -1;
//	while (*(s + (++i)) != 0);
//	return (i);
//}

