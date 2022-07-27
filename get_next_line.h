/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:18:03 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/27 21:55:31 by rjeong           ###   ########.fr       */
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

char	*ft_str_move(char *dst, char *src, int len);
char	*ft_result_join(t_str *s, char *str, int str_len);
char	*ft_str_return(t_str *result);

char	*ft_is_nl_in_left(t_str *left, int i);
void	ft_no_nl_in_left(t_str *result, t_str *left);
char	*ft_read_line(int fd, t_str *result, t_str *left);
void	ft_left(t_str *left, char *buff, int i);
char	*get_next_line(int fd);

#endif
