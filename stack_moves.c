/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:39:34 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/02/20 22:07:37 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa(t_list **stack, char a_or_b)
{
	t_list	*list;

	if (!*stack || !stack)
		return ;
	list = *stack;
	if (list && list->next)
		swap(&list->data, &list->next->data);
	if (a_or_b == 'a')
		printf("sa\n");
	else if (a_or_b == 'b')
		printf("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a, 'a');
	ft_sa(stack_b, 'b');
	printf("ss\n");
}

void	ft_ra(t_list **stack, char a_or_b)
{
	t_list	*first;
	t_list	*tmp;

	first = *stack;
	ft_lstlast(*stack);
	tmp = malloc (sizeof(t_list));
	tmp->data = first->data;
	*stack = first->next;
	free(first);
	ft_lstlast(*stack)->next = tmp;
	if (a_or_b == 'a')
		printf("ra\n");
	else if (a_or_b == 'b')
		printf("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a, 'a');
	ft_ra(stack_b, 'b');
	printf("rr\n");
}

t_list	*ft_rra(t_list **stack, char a_or_b)
{
	t_list		*tmp;
	int			swap;
	t_list		*list;

	tmp = ft_lstlast(*stack);
	swap = tmp->data;
	ft_before_last(*stack)->next = NULL;
	free (tmp);
	list = malloc(sizeof(t_list));
	list->data = swap;
	ft_lstadd_front(stack, list);
	if (a_or_b == 'a')
		printf("rra\n");
	else if (a_or_b == 'b')
		printf("rrb\n");
	return (list);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a, 'a');
	ft_rra(stack_b, 'b');
	printf ("rrr\n");
}

t_list	*ft_before_last(t_list *begin)
{
	if (!begin)
		return (NULL);
	while (begin->next->next)
	{
		begin = begin->next;
	}
	return (begin);
}

// void f()
// {
// 	system("leaks a.out");
// }

// int main()
// {
// 	// atexit(f);
// 	t_list *node1=malloc(sizeof(t_list));
// 	t_list *node2=malloc(sizeof(t_list));
// 	t_list *node3=malloc(sizeof(t_list));

// 	node1->data = 2;
// 	node2->data = 1;
// 	node3->data = 3;
// 	node1->next = node2;
// 	node2 ->next = node3;
// 	node3->next = NULL;
// 	t_list *tmp = node1;
// 	t_list *tmp2 = node1;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->data);
// 		tmp=tmp->next;
// 	}
// 	ft_sa(&node1, 'a');
// 	printf("-----------\n");
// 	// t_list *tmpp = ft_rra(&node1, 'a');
// 	while (tmp2)
// 	{
// 		printf("%d\n", tmp2->data);
// 		t_list *f = tmp2;
// 		tmp2=tmp2->next;
// 		free(f);
// 	}
// }
