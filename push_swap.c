/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/13 22:30:35 by ysantos-         ###   ########.fr       */
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
	ft_printf("%sError%s\n", YEL, CRESET);
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
			{printf("\t\tduplicated\n");
				error_print(start);
			}
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
		if (tmp == 0 && args[i][1]){printf("tmp == %i arg == %s\n", tmp, args[i]);
			return (0);
}		end->nxt = get_stack(tmp);
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

	if (argc <= 2)
		exit(0);
	if (!arg_check(argv, argc, &stk_a))
		error_print(&stk_a);
//printf("%slist a:%s\n", CYN, CRESET); 	print_list(&stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(&stk_b);
//push_stk(&stk_a, &stk_b, 1);
//push_stk(&stk_a, &stk_b, 1);
//b_to_a(&stk_a, &stk_b);
//swap_stk(&stk_a, 1);
//printf("%slist a:%s\n", CYN, CRESET); 	print_list(&stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(&stk_b);
//swap_both(&stk_a, &stk_b);
	get_order(&stk_a, &stk_b);
printf("%slist a:%s\n", CYN, CRESET); 	print_list(&stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(&stk_b);
printf("end \e[0;35m LEAKS \e[0m \n");
	return (0);
}
