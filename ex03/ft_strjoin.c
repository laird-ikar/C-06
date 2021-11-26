/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:54:27 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/26 08:42:58 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_strslen(char **strs, int size);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;

	if (!size)
	{
		tab = (char *) malloc(0);
		return (tab);
	}
	tab = malloc(sizeof(*tab)
			* (ft_strlen(sep) * (size - 1)
				+ ft_strslen(strs, size) + 1));
	if (!tab)
		return (NULL);
	tab = ft_strcat(tab, strs[0]);
	i = 1;
	while (i < size)
	{
		tab = ft_strcat(tab, sep);
		tab = ft_strcat(tab, strs[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	*ft_strcat(char *dest, char *src)
{
	int	size;
	int	i;

	size = 0;
	while (dest[size])
		size++;
	i = 0;
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[i + size] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strslen(char **strs, int size)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (++i < size)
		res += ft_strlen(strs[i]);
	return (res);
}
