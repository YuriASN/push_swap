/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:54 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 15:14:29 by ysantos-         ###   ########.fr       */
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

void	get_order(t_stk *stk_a, t_stk *stk_b);
int		check_order(t_stk *stack);
int		check_order_r(t_stk *stack);
int		swap_a(int *stk_a, int print);
int		swap_b(int *stk_b, int print);
int		swap_both(int *stk_a, int *stk_b);
int		push_a(int *stk_a, int *stk_b);
int		push_b(int *stk_a, int *stk_b);
int		rotate_a(int *stk_a, int print);
int		rotate_b(int *stk_b, int print);
int		rotate_both(int *stk_a, int *stk_b);
int		rotate_back_a(int *stk_a, int print);
int		rotate_back_b(int *stk_b, int print);
int		rotate_back_both(int *stk_a, int *stk_b);
void	b_to_a(int *stk_a, int *stk_b);
int		*get_lowest(t_stk *stk_a);
void	del_data(void *data);
t_stk	*get_stack(t_stk **stack, int value);
t_stk	*ft_stklast(t_stk *lst);

#endif