/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:54:27 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/24 15:40:23 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		strs_size(char **strs, int size);
char	*ft_strjoin(int size, char **strs, char *sep);
void	recur_fill_tab(char *tab, char **strs, char *sep, int size);
void	fill_tab(char *tab, char **strs, char *sep, int total_size);
void	put_separator(char *tab, int *i, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_size;
	char	*tab;

	if (size == 0)
	{
		tab = (char *) malloc (0);
		return (tab);
	}
	i = 0;
	total_size = strs_size(strs, size);
	i = 0;
	while (sep[i])
	{
		total_size += size - 1;
		i++;
	}
	tab = (char *) malloc(total_size);
	if (!tab)
		return (NULL);
	fill_tab(tab, strs, sep, total_size);
	return (tab);
}

void	fill_tab(char *tab, char **strs, char *sep, int total_size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	put_separator(tab, &i, sep);
	j = 1;
	while (i < total_size)
	{
		put_separator(tab, &i, sep);
		k = 0;
		while (strs[j][k])
		{
			tab[i] = strs[j][k];
			k++;
			i++;
		}
		j++;
	}
}

int	strs_size(char **strs, int size)
{
	int	i;
	int	j;
	int	total_size;

	i = 0;
	total_size = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			total_size++;
			j++;
		}
		i++;
	}
	return (total_size);
}

void	put_separator(char *tab, int *i, char *sep)
{
	int	k;

	k = 0;
	while (sep[k])
	{
		tab[*i] = sep[k];
		k++;
		(*i)++;
	}
}
