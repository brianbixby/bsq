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

void print(char *arr)
{
	while (*arr)
		ft_putchar(*arr++);
}

void iprint(int *arr, int m, int n)
{
	int i;
	int j;
	int k;

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

void	ft_fillbsq(bsq_struct *bsq)
{
	int i;
	int j;
	int beg_x;
	int beg_y;

	i = -1;
	beg_x = bsq->max_x + 1 - bsq->max_square_size;
	beg_y = bsq->max_y + 1 - bsq->max_square_size;
	printf("%d", bsq->max_square_size);
	printf("%c", '\n');
	while (++i <= bsq->max_square_size)
	{
		j = -1;
		while (++j < bsq->max_square_size)
		{
			if (beg_y + i == 1)
			{
			bsq->bsq_copy[beg_x + j] = bsq->full;
			}
			else
			{
			bsq->bsq_copy[(beg_y + i - 1) * (bsq->cols) + beg_x + j] = bsq->full;
			}
		}
	}
	ft_putchar('\n');
	print(bsq->bsq_copy);
}

void	ft_create_copies(bsq_struct *bsq, char **argv)
{
	char 	*cdup;
	int		idup[bsq->rows][bsq->cols - 1];
	int i;
	int j;
	int b;
	int k;

	int fd;
	int ret;
	fd = open(*argv, O_RDONLY);
	char *buf;
	bsq->max_square_size = 0;
	cdup = (char *)malloc(sizeof(char) * (bsq->rows * bsq->cols + 1));
	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	i = 0;
	j = 0;
	b = 0;
	k = 0;
	ft_putchar('\n');
	while ((ret = read(fd, buf, BUF_SIZE )))
	{
		while (b < bsq->r1_offset)
		{
			printf("%d", b);
			printf("%c", '\n');
			b++;
		}
		while (b - bsq->r1_offset < bsq->rows * bsq->cols)
		{
			cdup[k] = buf[b];
			k++;
			if (buf[b] == '\n')
			{
    			i++;
				b++;
    			j = 0;
				printf("%c",'\n');
				printf("%c", '\n');
  			}
			else
  			{
				if (i == 0 || j == 0)
					if (buf[b] == bsq->empty)
						idup[i][j] = 1;
					else
						idup[i][j] = 0;
				else if (buf[b] == bsq->empty)
    			{
      				idup[i][j] = 1 + (ft_min(idup[i][j - 1], idup[i - 1][j], idup[i - 1][j - 1]));
    			}
    			else
      				idup[i][j] = 0;
				if (idup[i][j] > bsq->max_square_size)
				{
					bsq->max_square_size = idup[i][j];
					bsq->max_y = i;
					bsq->max_x = j;
				}
				printf("%d",idup[i][j]);
    			j++;
				b++;
  			}
		}
		printf("max square size %d \n", bsq->max_square_size);
		printf("max x %d \n", bsq->max_x);
		printf("max y %d \n", bsq->max_y);
		buf[ret] = '\0';
		bsq->bsq_copy = cdup;
	}
	/* iprint((int *)&idup[0][0], bsq->rows, bsq->cols); */
	print(bsq->bsq_copy);
	ft_fillbsq(bsq);
}

bsq_struct	*ft_setvars(char *row, int i, int j)
{
	bsq_struct	*bsq;

	bsq = malloc(sizeof(bsq_struct));
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
	char 	*buf;
	int 	i;
	int		j;
	char 	row[100];

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
		break;
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
