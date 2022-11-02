/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:54 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/02 20:28:24 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	get_order(int *stack_a, int *stack_b);
int		check_order(int *stack);
int		check_order_r(int *stack);
int		get_last(int *stack);
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

#endif