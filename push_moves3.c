/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:46:10 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/03 21:28:19 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rrr : rra and rrb at the same time.
int	rotate_back_both(int *st_a, int *st_b)
{
	rotate_back_a(st_a, 0);
	rotate_back_b(st_b, 0);
	ft_printf("rrr\n");
	int i= -1;
	while (st_a[++i] || st_b[i])
		ft_printf("%i\t%i\n", st_a[i], st_b[i]);
	return (1);
}

void	b_to_a(int *st_a, int *st_b)
{
	ft_printf("b to a %i\n", st_b[0]);
	while (st_b[0]){printf("entrei");
		push_a(st_a, st_b);
	}
}
