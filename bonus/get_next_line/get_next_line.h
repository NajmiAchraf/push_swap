/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:13:24 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 18:37:52 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin2(char *s1, char *s2, int readsize);
char	*ft_substr2(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

void	freeing(char **to_free);
char	*error(char *buffer, char **save);
char	*get_next_line(int fd);

#endif