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
char	*ft_str_move(char *dst, char *src, int len);
void	ft_result_join(t_str *result, char *str, int str_len);
char	*ft_str_return(t_str *result, char *buff);

#endif
