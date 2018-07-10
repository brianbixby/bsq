/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrsilva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:05:49 by chrsilva          #+#    #+#             */
/*   Updated: 2018/07/10 08:06:42 by chrsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> // rand(), atoi();
#include <time.h> // time();




int main(int argc, char **argv)
{
	int x;
	int y;
	int density;
	int i;
	int j;

	if (argc != 4)
	{
		printf("Error.");
		return(0);
	}
	
	x		=	atoi(argv[1]);
	y		=	atoi(argv[2]);
	density	=	atoi(argv[3]);

	srand(time(0));	// seed for rand(), for extra randomness
	printf("%d.ox\n", y);
	
	i = 0;
	while(i < y)
	{
		j = 0;
		while(j < x)
		{
			// cool boolean
			if (((rand() % y) * 2) < density)
			{
				printf("o");
			}
		else
			{
				printf(".");
			}
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
