
#include "push_swap.h"

/* Deletes and frees the given node and every
successor of that node, using the function ’del’ and free.
Finally, the pointer to the list must be set to NULL. */
void	stkclear(t_stk *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		lst->value = 0;
		lst = lst->nxt;
	}
	lst = NULL;
}

//Free stk before quiting.
void	clean_quit(t_stk *stk)
{
printf("Clean quit!\n");
printf("%slist:%s\n", CYN, CRESET); 	print_list(stk);
	stkclear(stk);
	exit (0);
}






/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TO BE REMOVED! */
void	print_list(t_stk *lst){
	if (!lst->nxt)
		return ;
	while (lst->nxt)
	{
		ft_printf("%i\n", lst->nxt->value);
		lst = lst->nxt;
	}
	printf("\n");
}
