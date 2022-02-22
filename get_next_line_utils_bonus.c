/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:44:05 by mmoutawa          #+#    #+#             */
/*   Updated: 2021/12/11 08:24:42 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*p;

	if (s2 == NULL)
		return ((char *)s1);
	i = ft_strlen (s1);
	j = ft_strlen (s2);
	p = malloc(i + j + 1);
	if (p == NULL)
		return (NULL);
	j = 0;
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
			p[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
		p[j++] = s2[i++];
	p[j] = '\0';
	free (s1);
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	dst = (char *)malloc(i + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		dst[j] = s1[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
