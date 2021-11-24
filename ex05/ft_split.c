/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:23:10 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/24 15:01:04 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
int		is_in_charset(char c, char *charset);
void	set_nb_str(int *nb_str, int index[3], char *str, char *charset);
void	cpy_into_res(int index[3], char *str, char *charset, char ***res);
void	set_size_strs(int index[3], char *str, int **size_strs, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		*size_strs;
	int		nb_str;
	int		index[3];

	set_nb_str(&nb_str, index, str, charset);
	size_strs = malloc(sizeof(int) * nb_str);
	if (!size_strs)
		return (NULL);
	set_size_strs(index, str, &size_strs, charset);
	res = malloc(sizeof(char *) * nb_str + 1);
	if (!res)
	{
		return (NULL);
	}
	index[0] = 0;
	index[1] = 0;
	while (index[0] < nb_str)
	{
		res[index[0]] = malloc (size_strs[index[0]] + 1);
		index[0]++;
	}
	res[index[0]] = NULL;
	cpy_into_res(index, str, charset, &res);
	return (res);
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

void	set_nb_str(int *nb_str, int index[3], char *str, char *charset)
{
	index[0] = 0;
	index[1] = 0;
	nb_str = 0;
	while (str[index[0]])
	{
		if (is_in_charset(str[index[0]], charset)
			&& index[1] != 0)
		{
			nb_str++;
			index[1] = 0;
		}
		else
		{
			index[1]++;
		}
		index[0]++;
	}
	if (!is_in_charset(str[index[0] - 1], charset))
		nb_str++;
}

void	cpy_into_res(int index[3], char *str, char *charset, char ***res)
{
	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	while (str[index[0]])
	{
		if (is_in_charset(str[index[0]], charset)
			&& index[2])
		{
			index[2] = 0;
			index[1]++;
		}
		if (!(is_in_charset(str[index[0]], charset)))
		{
			(*res)[index[1]][index[2]] = str[index[0]];
			index[2]++;
		}
		(*res)[index[1]][index[2]] = '\0';
		index[0]++;
	}
}

void	set_size_strs(int index[3], char *str, int **size_strs, char *charset)
{
	index[0] = 0;
	index[1] = 0;
	while (str[index[0]])
	{
		if (is_in_charset(str[index[0]], charset)
			&& (*size_strs)[index[1]] != 0)
		{
			index[1]++;
			(*size_strs)[index[1]] = 0;
		}
		else
		{
			(*size_strs)[index[1]]++;
		}
		index[0]++;
	}
}
