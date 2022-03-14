/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:13:21 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 18:38:46 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *line, char *save)
{
	if (!save || ft_strlen(save) == 0)
		return (NULL);
	else if (ft_strchr(save, '\n'))
		line = ft_substr2(save, 0,
				ft_strlen(save) - ft_strlen(ft_strchr(save, '\n')) + 1);
	else
		line = ft_substr2(save, 0, ft_strlen(save));
	return (line);
}

char	*get_save(char *save)
{
	char	*tmp;

	tmp = NULL;
	if (!save)
		return (NULL);
	if (ft_strchr(save, '\n'))
		tmp = ft_substr2(ft_strchr(save, '\n') + 1, 0,
				ft_strlen(ft_strchr(save, '\n')));
	else
	{
		freeing(&save);
		return (NULL);
	}
	freeing(&save);
	return (tmp);
}

void	freeing(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

char	*error(char *buffer, char **save)
{
	freeing(&buffer);
	freeing(&(*save));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;
	int			readsize;

	line = NULL;
	readsize = 1;
	if (fd < 0)
		return (NULL);
	buffer = malloc(2 * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!save)
		save = ft_substr2("", 0, 1);
	while (readsize > 0 && !ft_strchr(save, '\n'))
	{
		readsize = read(fd, buffer, 1);
		if (readsize < 0)
			return (error(buffer, &save));
		save = ft_strjoin2(save, buffer, readsize);
	}
	freeing(&buffer);
	line = get_line(line, save);
	save = get_save(save);
	return (line);
}
