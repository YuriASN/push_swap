/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:54 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 14:03:01 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct t_stlst
{
	int				value;
	struct t_stlst	*nxt;
	struct t_stlst	*prev;
}	t_stk;

void	get_order(int *stack_a, int *stack_b);
int		check_order(t_stk *stack);
int		check_order_r(t_stk *stack);
int		swap_a(int *st_a, int print);
int		swap_b(int *st_b, int print);
int		swap_both(int *st_a, int *st_b);
int		push_a(int *st_a, int *st_b);
int		push_b(int *st_a, int *st_b);
int		rotate_a(int *st_a, int print);
int		rotate_b(int *st_b, int print);
int		rotate_both(int *st_a, int *st_b);
int		rotate_back_a(int *st_a, int print);
int		rotate_back_b(int *st_b, int print);
int		rotate_back_both(int *st_a, int *st_b);
void	b_to_a(int *st_a, int *st_b);
t_stk	*get_lowest(t_stk *st_a);
t_stk	*get_stack(t_stk **stack, int value);
void	del_data(void *data);

#endif