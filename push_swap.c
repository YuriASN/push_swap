/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/10 02:03:15 by ysantos-         ###   ########.fr       */
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
static int	error_print(t_stk *stk_a)
{
	stkclear(stk_a);
	ft_printf("Error\n");
	exit (0);
}

/* static void	print_list(t_stk *lst){
	while (lst)
	{
		ft_printf("%i\n", lst->value);
		lst = lst->nxt;
	}
} */

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
		if (!tmp && args[i][2])
			return (0);
		end->nxt = get_stack(tmp);
		end->nxt->prev = end;
		end = end->nxt;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	static t_stk	stack_a;
	static t_stk	stack_b;

	if (argc <= 2)
		exit(0);
	if (!arg_check(argv, argc, &stack_a))
		error_print(&stack_a);
//print_list(stack_a.nxt);
//rotate_rev(&stack_a, 1;
//print_list(stack_a.nxt);
//printf("\nlesgo\n");
//print_list(stack_b.nxt);
	get_order(&stack_a, &stack_b);
ft_printf("end \e[0;35m LEAKS \e[0m \n");
	return (0);
}
