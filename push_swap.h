/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:29:14 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/24 02:56:56 by ysantos-         ###   ########.fr       */
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
# define INT_MAX 2147483647

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
int		order_loop(t_stk *stk);
int		order_loop_rev(t_stk *stk);
int		fix_loop(t_stk *stk, int rev);
void	swap_stk(t_stk *stack, int print);
void	swap_both(t_stk *stk_a, t_stk *stk_b);
void	push_stk(t_stk *st_out, t_stk *st_in, int print);
void	rotate_stk(t_stk *stack, int print);
void	rotate_both(t_stk *stk_a, t_stk *stk_b);
void	rotate_rev(t_stk *stack, int print);
void	rotate_rev_both(t_stk *stk_a, t_stk *stk_b);
void	b_to_a(t_stk *stk_a, t_stk *stk_b);
int		get_lowest_moves(int **move, int b_size);
void	stkclear(t_stk *lst);
void	clean_quit(t_stk *stk);
t_stk	*stklast(t_stk *lst);
int		stksize(t_stk *lst);
int		get_lowest(t_stk *stk);
int		get_highest(t_stk *stk);
int		highest_value(t_stk *stk);
void	order_big(t_stk *stk_a, t_stk *stk_b);
void	less_moves(t_stk *stk_a, t_stk *stk_b);
int		lowest_value(t_stk *stk);

#endif