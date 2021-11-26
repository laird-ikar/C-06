/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:23:10 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/26 09:38:17 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_split
{
	unsigned int	size;
	char			*beg;
}	t_split;

t_split	get_split(char *str, char *charset, int i);
char	**ft_split(char *str, char *charset);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		is_in_charset(char c, char *charset);
int		get_nb_splits(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**splits;
	int		nb_splits;
	int		i;
	t_split	split;

	nb_splits = get_nb_splits(str, charset);
	splits = (char **) malloc(sizeof(*splits) * (nb_splits + 1));
	i = 0;
	while (i < nb_splits)
	{
		split = get_split(str, charset, i);
		splits[i] = malloc(sizeof(**splits) * split.size);
		splits[i] = ft_strncpy(splits[i], split.beg, split.size);
		i++;
	}
	splits[nb_splits] = 0;
	return (splits);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

t_split	get_split(char *str, char *charset, int nb)
{
	t_split	split;
	int		i;

	i = 0;
	while (is_in_charset(str[i], charset))
		i++;
	while (nb >= 0)
	{
		split.size = 0;
		split.beg = str + i;
		while (!is_in_charset(str[i], charset))
		{
			split.size++;
			i++;
		}
		while (is_in_charset(str[i], charset))
			i++;
		nb--;
	}
	return (split);
}

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int	get_nb_splits(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (is_in_charset(str[i], charset) && str[i])
		i++;
	while (str[i])
	{
		while (!is_in_charset(str[i], charset) && str[i])
		{
			i++;
		}
		while (is_in_charset(str[i], charset) && str[i])
			i++;
		count++;
	}
	return (count);
}
