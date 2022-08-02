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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	char	*str;
	ssize_t	size;
}	t_data;

void	ft_str_move(char *dst, char *src, ssize_t len);
int		ft_data_join(t_data *data, char *src, ssize_t len);
void	ft_check_remain(t_data *remain, t_data *buff, int fd);
int		ft_check_buff(t_data *buff, t_data *result, t_data *remain);
char	*get_next_line(int fd);

#endif
