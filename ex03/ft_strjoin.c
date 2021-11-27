/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:54:27 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/27 15:11:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_str_concat(char *tab, int size, char **strs, char *sep);
int		ft_str_compt(int size, char **strs, char *sep);
int		ft_strlen(char *str);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		size_all;
	char	*tab;

	size_all = ft_strslen(size, strs, sep);
	tab = malloc(sizeof(char) * size_all);
	big_concat(tab, size, strs, sep);
}

void	big_concat(char *tab, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			tab[l++] = strs[i][j++];
		if (i != size - 1)
		{
			j = 0;
			while (sep[k])
				tab[l++] = sep[j++];
		}
		i++;
	}
	tab[l] = 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strslen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		i++;
		len += j;
		j = 0;
		while (i < size && sep[j])
			j++;
		len += j;
	}
	return (len);
}
