/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:49:45 by bbixby            #+#    #+#             */
/*   Updated: 2018/07/09 16:07:13 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnum(int i)
{
	int	denom;
	int	nb;

	denom = 10;
	nb = i;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	while (nb / denom >= 10)
		denom *= 10;
	while (denom >= 10)
	{
		ft_putchar(nb / denom + '0');
		nb %= denom;
		denom /= 10;
	}
	if (i != 0)
		ft_putchar(nb + '0');
}

int		ft_atoi(char *str, int i)
{
	int	count;
	int	neg;
	int j;

	neg = 1;
	count = 0;
	j = 0;
	while (str[j] == '\t' || str[j] == '\n' || str[j] == '\v'
		|| str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			neg = -1;
		j++;
	}
	while (str[j] <= '9' && str[j] >= '0' && j < i)
	{
		count *= 10;
		count += (*str - '0');
		j++;
	}
	count *= neg;
	return (count);
}

int		ft_rowlen(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}
