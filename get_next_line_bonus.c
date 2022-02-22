/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:58 by mmoutawa          #+#    #+#             */
/*   Updated: 2021/12/11 08:17:08 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_zron(char *u)
{
	int		i;

	i = 0;
	if (!u)
		return (0);
	while (u[i])
	{
		if (u[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_nxln(char *p)
{
	int		i;
	char	*u;

	i = 0;
	if (!p)
		return (NULL);
	while (p[i])
	{
		if (p[i] == '\n')
		{
			u = ft_substr(p, i + 1, ft_strlen(p) - i);
			free (p);
			return (u);
		}
		i++;
	}
	free (p);
	return (NULL);
}

char	*ft_cln(char *res)
{
	int	i;

	i = 0;
	if (!res[0])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	return (ft_substr(res, 0, i + 1));
}

char	*ft_rdln(int fd, char *u)
{
	char	*p;
	int		x;

	x = 1;
	p = NULL;
	p = malloc(BUFFER_SIZE + 1);
	if (!p)
		return (NULL);
	while (!ft_zron(u) && x)
	{
		x = read(fd, p, BUFFER_SIZE);
		if (x == -1)
		{
			free(p);
			return (NULL);
		}
		p[x] = '\0';
		u = ft_strjoin(u, p);
	}
	free (p);
	return (u);
}

char	*get_next_line(int fd)
{
	static char	*u[1024];
	char		*p;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	u[fd] = ft_rdln(fd, u[fd]);
	if (!u[fd])
		return (NULL);
	p = ft_cln(u[fd]);
	u[fd] = ft_nxln(u[fd]);
	return (p);
}
