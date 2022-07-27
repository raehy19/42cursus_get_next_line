/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:18:03 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/19 17:18:07 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_str
{
	char	*str;
	int		size;
}	t_str;


char	*get_next_line(int fd);
//int		ft_strlen(const char *s);
//char	*ft_join(char *s1, char *s2, int s2_start, int s2_len);
//char	*ft_join_n_free(char *s1, char *s2, int s2_start, int s2_len);
//void	*ft_memmove(void *dst, const void *src, int len);
//char	*ft_str_dup_move(char *src, int start, int len);
char	*ft_str_move(char *dst, char *src, int len);

void	ft_result_join(t_str *result, char *str, int str_len);
char	*ft_str_return(t_str *result);
#endif
