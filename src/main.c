/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:32:44 by bbixby            #+#    #+#             */
/*   Updated: 2018/07/09 20:49:15 by bbixby           ###   ########.fr       */
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

void	ft_create_copies(bsq_struct *bsq, char **argv)
{
	char	cdup[bsq->rows][bsq->cols - 1];
	int		idup[bsq->rows][bsq->cols - 1];
	int i;
	int j;
	int b;

	int fd;
	int ret;
	fd = open(*argv, O_RDONLY);
	char *buf;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	i = 0;
	j = 0;
	b = 0;
	ft_putchar('\n');
	while ((ret = read(fd, buf, BUF_SIZE )))
	{
		while (b != '\n')
			b++;
		if (b == '\n')
			b++;
		while (b < bsq->rows * bsq->cols + 1)
		{
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
    			cdup[i][j] = buf[b];
    			if (i != 0 && j != 0 && buf[b] != bsq->obstacle)
    			{
      				idup[i][j] = 1 + (ft_min(idup[i][j - 1], idup[i - 1][j], idup[i - 1][j - 1]));
    			}
    			else
      				idup[i][j] = 0;
				printf("%d" ,idup[i][j]);
    			j++;
				b++;
  			}
		}
		buf[ret] = '\0';
	}
}

void	ft_readfile(char **argv)
{
	int		fd;
	int		ret;
	int 	i;
	int		k;
	int 	have_rows;
	char 	rows[100];
	char *buf;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);

	bsq_struct	*bsq;

  	bsq = malloc(sizeof(bsq_struct));

	fd = open(*argv, O_RDONLY);
	i = 0;
	have_rows = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		while (buf[i] != '\n' && !have_rows)
		{
			rows[i] = buf[i];
			i++;
		}
		bsq->full = rows[i - 1];
		bsq->obstacle = rows[i - 2];
		bsq->empty = rows[i - 3];
    	bsq->rows = ft_atoi(rows);

		have_rows += 1;
		i++;
		k = 0;
		while (have_rows == 1 && buf[i] != '\n')
		{
			k++;
			i++;
		}
		have_rows += 1;
		bsq->cols = k + 1;

		buf[ret] = '\0';
		ft_putstr(buf);
	}
  ft_putchar(bsq->full);
  ft_putchar('\n');
  ft_putchar(bsq->obstacle);
  ft_putchar('\n');
  ft_putchar(bsq->empty);
  ft_putchar('\n');
  ft_putnum(bsq->rows);
  ft_putchar('\n');
  ft_putnum(bsq->cols);
  ft_create_copies(bsq, argv);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
		ft_readfile(argv + i);
	return (0);
}
