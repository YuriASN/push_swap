/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:54 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/13 14:39:50 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define WHT "\e[0;97m"
# define CYN "\e[0;96m"
# define MAG "\e[0;95m"
# define BLU "\e[0;94m"
# define YEL "\e[0;93m"
# define GRN "\e[0;92m"
# define RED "\e[0;91m"
# define BLK "\e[0;90m"
# define CRESET "\e[0m"

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
/* -------------------- Lists functions ----------------------------------- */
void	stkclear(t_stk *lst);
t_stk	*stklast(t_stk *lst);
int		stksize(t_stk *lst);
int		get_lowest(t_stk *stk);
void	print_list(t_stk *lst);

#endif