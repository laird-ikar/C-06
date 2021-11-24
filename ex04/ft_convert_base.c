/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:12:50 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/24 14:59:26 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);
int		is_valid(char *base);
void	add_char(int *value, char c, char *base);
int		is_in_base(char c, char *base);
void	sign_gestion(char *str, int *i, int *sign);
int		ft_strlen(char *str);
char	*ft_strbcat(char *beg, char *end, int size_beg, int size_end);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value;
	char	*str;

	if (!is_valid(base_from) || !is_valid(base_to))
	{
		return (NULL);
	}
	else
	{
		value = ft_atoi_base(nbr, base_from);
		str = ft_itoa_base(value, base_to);
		return (str);
	}
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*res;
	int		base_size;

	res = "";
	base_size = is_valid(base);
	if (nbr < 0)
	{
		res = ft_strbcat("-", ft_itoa_base(nbr / -base_size, base),
				1, ft_strlen(ft_itoa_base(nbr / -base_size, base)));
		res = ft_strbcat(res, &base[-(nbr % base_size)], ft_strlen(res), 1);
	}
	else
	{
		while (nbr >= base_size)
		{
			res = ft_strbcat(&base[nbr % base_size], res, 1, ft_strlen(res));
			nbr /= base_size;
		}
		res = ft_strbcat(&base[nbr % base_size], res, 1, ft_strlen(res));
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_size;
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	base_size = is_valid(base);
	if (base_size)
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		sign_gestion(str, &i, &sign);
		while (is_in_base(str[i], base))
		{
			add_char(&value, str[i], base);
			i++;
		}
	}
	return (sign * value);
}

void	add_char(int *value, char c, char *base)
{
	int	i;
	int	base_size;

	i = 0;
	base_size = is_valid(base);
	while (base[i] != c)
		i++;
	*value *= base_size;
	*value += i;
}

char	*ft_strbcat(char *beg, char *end, int size_beg, int size_end)
{
	char	*res;
	int		i;
	int		j;

	j = size_beg + size_end + 1;
	res = (char *) malloc(j);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (beg[i] && i < size_beg)
	{
		res[j] = beg[i];
		j++;
		i++;
	}
	i = 0;
	while (end[i] && i < size_end)
	{
		res[j] = end[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
