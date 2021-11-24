/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:20:37 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/24 14:58:38 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	ft_putnbr_base(int nbr, char *base);
char	*ft_itoa_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);
int		is_valid(char *base);
void	add_char(int *value, char c, char *base);
int		is_in_base(char c, char *base);
void	sign_gestion(char *str, int *i, int *sign);
int		ft_strlen(char *str);
char	*ft_strbcat(char *beg, char *end, int size_beg, int size_end);

int	is_valid(char *base)
{
	int	size;
	int	j;

	j = 0;
	size = 0;
	while (base[size])
	{
		if (base[size] == '+' || base[size] == '-'
			|| base[size] == ' ' || base[size] == '\n' || base[size] == '\f'
			|| base[size] == '\r' || base[size] == '\t' || base[size] == '\v')
			return (0);
		j = 0;
		while (j < size)
		{
			if (base[size] == base [j])
				return (0);
			j++;
		}
		size++;
	}
	if (size >= 2)
		return (size);
	else
		return (0);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
