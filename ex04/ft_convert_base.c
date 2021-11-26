/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:12:50 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/26 08:16:00 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	add_char(int *value, char c, char *base);
void	sign_gestion(char *str, int *i, int *sign);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa_base(int nb, char *base);
int		ft_digits(int nb, int base);
int		ft_abs(int n);
int		ft_atoi_base(char *str, char *base);
int		is_in_base(char c, char *base);
int		is_valid(char *base);

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

void	sign_gestion(char *str, int *i, int *sign)
{
	while (str[*i] == '+'
		|| str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}
