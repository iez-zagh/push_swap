/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:33 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/02/20 21:01:36 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// the nedeed libraries
# include <unistd.h>
# include <stdlib.h>
# include <libc.h>
# include "my_printf/ft_printf.h"

// for Ansi colors
# define RED_TEXT "\033[1;31m"
# define GREEN_TEXT "\033[1;32m"
# define YELLOW_TEXT "\033[1;33m"
# define RESET_TEXT "\033[0m"

// the stack structs
typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

// the funtions's prototype
int		ft_strlen(const char *s);
void	prepare_stack(int ac, char **av);
void	checker(const char *str);
t_list	*fill_stack_a(char *str, int size);
char	*ft_strjoin(const char *s1, const char *s2, int ac, int i1);
char	*ft_strdup(const char *s);
long	ft_atoi(char *s);
void	if_just_spaces(char *s);
char	**ft_split(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**fill(char const *str, char **p, int num_words);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	check_duplicate(t_list *node, int n);
int		check_the_smallest(char	*s);
t_list	*ft_before_last(t_list *begin);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_sa(t_list **stack_a, char a_or_b);
void	ft_ra(t_list **stack, char a_or_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
t_list	*ft_rra(t_list **stack, char a_or_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);

#endif