/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:28 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/18 16:18:26 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Link the given argument as last on the stack.
static t_stk	*get_stack(int value)
{
	t_stk	*new;

	new = (t_stk *)malloc(sizeof(t_stk));
	if (!new)
		return (NULL);
	new->value = value;
	new->nxt = NULL;
	return (new);
}

//Print error message and return 0
static void	error_print(t_stk *stk_a)
{
	stkclear(stk_a);
	write(2, "Error\n", 6);
	exit (0);
}

/* Check if there's a duplicated number*/
static void	check_duplicated(t_stk *stack)
{
	int		cmp;
	t_stk	*start;
	t_stk	*next;

	start = stack;
	next = stack->nxt;
	while (next->nxt)
	{
		cmp = next->value;
		stack = next->nxt;
		while (stack)
		{
			if (cmp == stack->value)
				error_print(start);
			stack = stack->nxt;
		}
		next = next->nxt;
	}
}

/* Check if the arguments received (except 1st 
as it is the name of the proogram) are all alphanumerics and int size.
Then it converts the argument to int and save it on the stack */
static int	arg_check(char **args, int max, t_stk *stack)
{
	int		i;
	int		k;
	int		tmp;
	t_stk	*end;

	i = 0;
	k = -1;
	end = stack;
	while (++i < max)
	{
		k = -1;
		if (args[i][0] == '-' || args[i][0] == '+')
			++k;
		while (args[i][++k])
			if (args[i][k] < 48 || args[i][k] > 57)
				return (0);
		tmp = ft_atoi(args[i]);
		if (tmp == 0 && args[i][1])
			error_print(stack);
		end->nxt = get_stack(tmp);
		end->nxt->prev = end;
		end = end->nxt;
	}
	check_duplicated(stack);
	return (1);
}

int	main(int argc, char *argv[])
{
	static t_stk	stk_a;
	static t_stk	stk_b;

	if (argc == 1)
		exit (0);
	if (!arg_check(argv, argc, &stk_a))
		error_print(&stk_a);
	if (argc <= 2)
	{
		stkclear(&stk_a);
		exit(0);
	}
	get_order(&stk_a, &stk_b);
	return (0);
}
