/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:44:02 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/25 16:09:48 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
#endif