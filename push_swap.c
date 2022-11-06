/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 13:50:02 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Print error message and return 0
static int	error_print(t_stk **st_a, t_stk **st_b)
{
	ft_lstclear(st_a, del_data);
	ft_lstclear(st_b, del_data);
	ft_printf("Error\n");
	exit (0);
}

/* Check if the arguments received (except 1st 
as it is the name of the proogram) are all alphanumerics and int size.
Then it converts the argument to int and save it on the stack */
static int	arg_check(char **args, int max, t_stk **stack)
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
		get_stack(stack, tmp);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stk	**stack_a;
	t_stk	**stack_b;

	if (argc <= 2)
		exit(0);
	if (!stack_a || !stack_b || !arg_check(argv, argc, stack_a))
		error_print(stack_a, stack_b);
	get_order(stack_a, stack_b);
	ft_printf("end \e[0;35m LEAKS \e[0m \n");

	return (0);
}
