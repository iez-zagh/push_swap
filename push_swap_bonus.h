/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:27:55 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/05 19:04:47 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
// the nedeed libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>


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
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
	int		mid_average;
	int		average_index;
}	t_stack;

t_stack	*prepare_stack2(int ac, char **av);
void	if_just_spaces2(char *s);
int		ft_lstsize2(t_list *node);
int		ft_strlen2(const char *s);
char	*ft_strdup2(const char *s);
char	*ft_strjoin2(const char *s1, const char *s2, int ac, int i1);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
void	checker2(const char *str);
char	**fill(char const *str, char **p, int num_words);
char	**ft_free2(char **p, int j);
void	ft_int(int *a, int *b, int *c);
int		count_count(const char *str);
int		check_the_smallest2(char	*s);
long	ft_atoi2(char *s);
void	check_duplicate2(t_list *node, int n);
void	ft_lstadd_front2(t_list **lst, t_list *new);
t_list	*ft_lstnew2(int content);
t_list	*ft_lstlast2(t_list *lst);
void	ft_lstadd_back2(t_list **lst, t_list *new);
char	**ft_split2(char const *s);
void	print_error2(void);
t_stack	*filling2(char **res);
int		check_if_sorted2(t_list **begin);
char	*get_next_line(int fd);
char	*ft_strjoin3(char *s1, char *s2);
int		ft_strlen3(char *str);
char	*ft_substr3(char *s, int start, int len);
char	*ft_strdup3(char *str);
int		ft_strchr3(char *str, char c);
void	apply(t_list **ins);
char	*ft_one_line(char *str, int j);
char	*check(char **buffer, int j);
char	*end_or_inv(int u, char **buffer);
char	*ft_read(int fd, char **buffer, char *str);
void	print_list2(t_list *tmp);
int		checking(char *res);

#endif