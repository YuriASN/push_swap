/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:56:41 by ysantos-          #+#    #+#             */
/*   Updated: 2022/10/31 22:55:56 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if stack A is completely on order and returns TRUE or FALSE.
int	check_order(int *stack)
{
	int	i;

	i = -1;
	while (stack[++i])
	{
		if (stack[i] > stack[i + 1])
			return (0);
	}
	return (1);
}

// Check if stack B is completely on reverse order and returns TRUE or FALSE.
int	check_order_r(int *stack)
{
	int	i;

	i = -1;
	while (stack[++i])
	{
		if (stack[i] < stack[i + 1])
			return (0);
	}
	return (1);
}

//Get position of last number on the stack and returns it.
int	get_last(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i - 1);
}
