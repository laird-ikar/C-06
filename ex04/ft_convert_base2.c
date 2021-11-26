/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:20:37 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/26 08:44:19 by bguyot           ###   ########.fr       */
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

char	*ft_itoa_base(int nb, char *base)
{
	int		base_size;
	int		i;
	int		sign;
	int		res_size;
	char	*res;

	base_size = is_valid(base);
	res_size = ft_digits(nb, base_size);
	sign = (nb < 0);
	res = malloc(sizeof(*res) * (res_size + 1 + sign));
	i = res_size - 1 + sign;
	while (i >= sign)
	{
		res[i] = base[ft_abs(nb % base_size)];
		nb /= base_size;
		i--;
	}
	if (sign)
		res[0] = '-';
	res[res_size + sign] = '\0';
	return (res);
}

int	ft_digits(int nb, int base)
{
	int	i;

	i = 1;
	if (nb > 0)
	{
		while (nb >= base)
		{
			nb /= base;
			i++;
		}
	}
	else
	{
		while (nb <= -base)
		{
			nb /= base;
			i++;
		}
	}
	return (i);
}

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

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
