/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:54 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 16:11:26 by ysantos-         ###   ########.fr       */
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
int		swap_stk(t_stk *stack, int print);
int		swap_both(t_stk *stk_a, t_stk *stk_b);
int		push_stk(t_stk *st_out, t_stk *st_in, int print);
int		rotate_stk(t_stk *stack, int print);
int		rotate_both(t_stk *stk_a, t_stk *stk_b);
int		rotate_rev(t_stk *stack, int print);
int		rotate_rev_both(t_stk *stk_a, t_stk *stk_b);
void	b_to_a(t_stk *stk_a, t_stk *stk_b);
int		*get_lowest(t_stk *stk_a);
void	del_data(void *data);
t_stk	*get_stack(t_stk **stack, int value);
t_stk	*ft_stklast(t_stk *lst);

#endif