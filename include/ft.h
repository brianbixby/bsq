/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:47:57 by bbixby            #+#    #+#             */
/*   Updated: 2018/07/09 20:57:06 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef struct    b_struct
{
  int             rows;
  int             cols;
  int				r1_offset;
  char            empty;
  char            obstacle;
  char            full;
}					bsq_struct;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnum(int i);
int		ft_atoi(char *str);
int		ft_rowlen(char *str);
void	fake(void);

#endif
