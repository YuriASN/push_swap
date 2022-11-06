/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 19:09:29 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Adds the node 'new' to the end of the list
lst: The address of a pointer to the 1st link of a list */
static void	stk_add_back(t_stk **lst, t_stk *new)
{
	t_stk	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = stklast(*lst);
	tmp->nxt = new;
}

// Link the given argument as last on the stack.
static t_stk	*get_stack(t_stk *stack, int value)
{
	t_stk	*new;

	new = (t_stk *)malloc(sizeof(t_stk));
	if (!new)
		return (NULL);
	new->value = value;
	new->nxt = NULL;
	if (!stack)
	{
		stack = new;
		new->prev = NULL;
	}
	else
	{
		stk_add_back(&stack, new);
		new->prev = stklast(stack);
	}
	return (new);
}

//Print error message and return 0
static int	error_print(t_stk *stk_a)
{
	stkclear(stk_a);
	ft_printf("Error\n");
	exit (0);
}

/* Check if the arguments received (except 1st 
as it is the name of the proogram) are all alphanumerics and int size.
Then it converts the argument to int and save it on the stack */
static int	arg_check(char **args, int max, t_stk *stack)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	k = -1;
	while (++i < max)
	{
		k = -1;
		if (args[i][0] == '-' || args[i][0] == '+')
			++k;
		while (args[i][++k])
			if (args[i][k] < 48 || args[i][k] > 57)
				return (0);
		tmp = ft_atoi(args[i]);
		if (!tmp && args[i][2])
			return (0);
		if (!get_stack(stack, tmp))
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stk	*stack_a;

	stack_a = (t_stk *)malloc(sizeof(t_stk));
	if (argc <= 2)
		exit(0);
	if (!arg_check(argv, argc, stack_a))
		error_print(stack_a);
	get_order(stack_a);
	ft_printf("end \e[0;35m LEAKS \e[0m \n");
	return (0);
}
