/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:33 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/04 22:30:32 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// the nedeed libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// for Ansi colors
# define RED_TEXT "\033[1:31m"
# define GREEN_TEXT "\033[1;32m"
# define YELLOW_TEXT "\033[1;33m"
# define RESET_TEXT "\033[0m"

// the stack structs
typedef struct s_list
{
	int				data;
	struct s_list	*next;
	int				cost;
	struct s_list	*target;
	int				index_to_m;
	int				index;
	int				index_b;
	int				cost2;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
	int		mid_average;
	int		average_index;
}	t_stack;

// the funtions's prototype
void	print_error(void);
void	sort2_3(t_stack *stack);
int		ft_strlen(const char *s);
void	prepare_stack(int ac, char **av);
void	checker(const char *str);
char	*ft_strjoin(const char *s1, const char *s2, int ac, int i1);
char	*ft_strdup(const char *s);
long	ft_atoi(char *s);
void	if_just_spaces(char *s);
char	**ft_split(char const *s);
void	swap(int *a, int *b);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**fill(char const *strc, char **p, int num_words);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	check_duplicate(t_list *node, int n);
int		check_the_smallest(char	*s);
t_list	*ft_before_last(t_list *begin);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_sa(t_list **stack_a, char a_or_b);
t_list	*ft_ra(t_list **stack, char a_or_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_stack *sstack, char a_or_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);
t_list	*ft_pb(t_list **stack_a, t_list **stack_b);
int		ft_lstsize(t_list *node);
int		check_if_sorted(t_list **begin);
t_list	*ft_pa(t_list **stack_a, t_list **stack_b);
void	filling(char **res);
t_list	*ft_max(t_list *node);
t_list	*ft_min(t_list *node);
void	indexing(t_stack *stack_a);
void	sort3(t_stack *stack_a);
void	sort_4(t_stack *stack);
t_list	*get_min_top(t_stack *stack, t_list *tmp);
void	sort_5(t_stack *stack);
void	move_to_b(t_stack *sstack_a);
t_list	*find_target(int y, t_list *stack);
void	geting_targets(t_stack *sstack_a, t_stack *sstack_b);
void	count_cost(t_stack *sstack_b, t_stack *sstack_a);
void	geting_count(t_stack *stack);
t_list	*ft_min_cost(t_stack *stack);
void	get_min_top2(t_stack *stack_a, t_stack *stack_b, t_list *tmp);
void	sorting(t_stack *sstack_a, t_stack *sstack_b);
int		reducing(t_stack *stack_a, t_stack *stack_b, t_list **tmp);
void	moving(t_stack *stack_a, t_stack *stack_b, t_list **tmp);
void	pushing_to_b(t_stack **sstack_a, t_list **stack_a, t_list **stack_b);
void	sort_the_rest(t_stack *stack_a, t_stack *stack_b, int j, t_list *tmp);
void	sort0(t_stack *stack_a);

#endif
