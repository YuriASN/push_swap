/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/02 20:20:40 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Print error message and return 0
static int	error_print(int *st_a, int *st_b)
{
	free(st_a);
	free(st_b);
	ft_printf("Error\n");
	exit (0);
}

/* Check if the arguments received (except 1st 
as it is the name of the proogram) are all alphanumerics.
Then it converts the argument to int and save it on the stack */
static int	arg_check(char **args, int max, int *stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = -1;
	while (++i < max)
	{
		while (args[i][++k])
		{
			if (args[i][k] < 48 || args[i][k] > 57)
				return (0);
		}
		stack[++j] = ft_atoi(args[i]);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	if (argc < 3)
		exit(0);
	stack_a = (int *)ft_calloc(sizeof(int), argc);
	stack_b = (int *)ft_calloc(sizeof(int), argc);
	if (!stack_a || !stack_b || !arg_check(argv, argc, stack_a))
		error_print(stack_a, stack_b);
	get_order(stack_a, stack_b);
	return (0);
}
