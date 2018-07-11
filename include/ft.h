/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:47:57 by bbixby            #+#    #+#             */
/*   Updated: 2018/07/09 22:14:39 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef struct		s_b_struct
{
	int				rows;
	int				cols;
	int				r1_offset;
	int				max_x;
	int				max_y;
	int				max_square_size;
	char			empty;
	char			obstacle;
	char			full;
	char			*bsq_copy;
}					t_bsq_struct;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnum(int i);
int					ft_atoi(char *str, int i);
int					ft_rowlen(char *str);
void				fake(void);

#endif
