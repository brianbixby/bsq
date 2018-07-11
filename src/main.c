/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:32:44 by bbixby            #+#    #+#             */
/*   Updated: 2018/07/10 14:54:06 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "./../include/ft.h"

#define BUF_SIZE 9999

int		ft_min(int a, int b, int c)
{
	int		m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	iprint(int *arr, int m, int n)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			printf("%d", *arr);
			k++;
		}
		printf("%c", '\n');
		printf("%d", *arr);
		printf("%c", '\n');
	}
}

void	ft_fillbsq(t_bsq_struct *bsq)
{
	int i;
	int j;
	int beg_x;
	int beg_y;

	i = -1;
	beg_x = bsq->max_x + 1 - bsq->max_square_size;
	beg_y = bsq->max_y + 1 - bsq->max_square_size;
	while (++i <= bsq->max_square_size)
	{
		j = -1;
		while (++j < bsq->max_square_size)
		{
			if (beg_y + i == 1)
				bsq->bsq_copy[beg_x + j] = bsq->full;
			else
				bsq->bsq_copy[(beg_y + i - 1) * (bsq->cols) + beg_x + j] = bsq->full;
		}
	}
	ft_putstr(bsq->bsq_copy);
}

void	ft_create_copies(t_bsq_struct *bsq, char **argv)
{
	int		idup[bsq->rows][bsq->cols - 1];
	char	*cdup;
	char	*buf;
	int		i;
	int		j;
	int		b;
	int		fd;

	fd = open(*argv, O_RDONLY);
	cdup = (char *)malloc(sizeof(char) * (bsq->rows * bsq->cols + 1));
	buf = (char *)malloc(sizeof(char) * (bsq->rows * bsq->cols + bsq->r1_offset));
	bsq->max_square_size = i = j = b = 0;
	while (read(fd, buf, bsq->rows * bsq->cols + bsq->r1_offset))
	{
		while (b < bsq->r1_offset)
			b++;
		while (b < bsq->rows * bsq->cols + bsq->r1_offset)
		{
			cdup[b - bsq->r1_offset] = buf[b];
			if (buf[b] == '\n')
			{
				i++;
				j = 0;
			}
			else
			{
				if (i == 0 || j == 0)
					buf[b] == bsq->empty ? (idup[i][j] = 1) : (idup[i][j] = 0);
				else if (buf[b] == bsq->empty)
					idup[i][j] = 1 + (ft_min(idup[i][j - 1], idup[i - 1][j], idup[i - 1][j - 1]));
				else
					idup[i][j] = 0;
				if (idup[i][j] > bsq->max_square_size)
				{
					bsq->max_square_size = idup[i][j];
					bsq->max_y = i;
					bsq->max_x = j;
				}
				j++;
			}
			b++;
		}
		buf[b] = '\0';
	}
	bsq->bsq_copy = cdup;
	free(buf);
	ft_fillbsq(bsq);
}

t_bsq_struct	*ft_setvars(char *row, int i, int j)
{
	t_bsq_struct	*bsq;

	bsq = malloc(sizeof(t_bsq_struct));
	bsq->full = row[i - j - 2];
	bsq->obstacle = row[i - j - 3];
	bsq->empty = row[i - j - 4];
	bsq->rows = ft_atoi(row, (i - j - 4));
	bsq->r1_offset = i - j;
	bsq->cols = j + 1;
	free(bsq);
	return (bsq);
}

void	ft_readr1(char **argv)
{
	char	*buf;
	int		i;
	int		j;
	char	row[100];

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	i = 0;
	j = 0;
	while (read(open(*argv, O_RDONLY), buf, BUF_SIZE))
	{
		while (buf[i] != '\n')
		{
			row[i] = buf[i];
			i++;
		}
		i++;
		while (buf[i] != '\n')
		{
			j++;
			i++;
		}
		break ;
	}
	free(buf);
	ft_create_copies(ft_setvars(row, i, j), argv);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
		ft_readr1(argv + i);
	return (0);
}
