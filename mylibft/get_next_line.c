/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:23:58 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/21 12:19:00 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_FD 10240

int		gnl_test_line(char **ln, char **line)
{
	char	*ptr_ln;
	char	*strchr_ln;
	int		i;

	i = 0;
	strchr_ln = *ln;
	while (strchr_ln[i] != '\n')
		if (!strchr_ln[i++])
			return (0);
	ptr_ln = &strchr_ln[i];
	*ptr_ln = '\0';
	free(*line);
	*line = ft_strdup(*ln);
	*ln = ft_strdup(ptr_ln + 1);
	free(strchr_ln);
	if (!*ln || !*line)
		return (-1);
	return (1);
}

int		gnl_read_file(int fd, char **ln, char **line, char *tmp)
{
	int		read_res;
	char	*tmp_ln;

	while ((read_res = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[read_res] = '\0';
		if (*ln)
		{
			tmp_ln = *ln;
			if (!(*ln = ft_strjoin(*ln, tmp)))
				return (-1);
			free(tmp_ln);
			tmp_ln = NULL;
		}
		else if (!(*ln = ft_strdup(tmp)))
			return (-1);
		if (gnl_test_line(ln, line) != 0)
			break ;
	}
	free(tmp);
	if (read_res == 0 && *ln)
		free(*line);
	if (read_res == 0 && *ln && !(*line = ft_strdup(*ln)))
		return (-1);
	return (read_res > 0 ? 1 : read_res);
}

int		get_next_line(int fd, char **line)
{
	static char		*ln[MAX_FD];
	char			*tmp;
	int				read_res;

	if (!line || (fd < 0 || fd > MAX_FD) || (read(fd, ln[fd], 0) < 0))
		return (-1);
	if (!(*line = ft_strdup("\0")))
		return (-1);
	if (ln[fd] && gnl_test_line(&ln[fd], line))
		return (1);
	if (!(tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	read_res = gnl_read_file(fd, &ln[fd], line, tmp);
	if (read_res != 0 || ln[fd] == NULL)
		return (read_res);
	free(ln[fd]);
	ln[fd] = NULL;
	return (0);
}
