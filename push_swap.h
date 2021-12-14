#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_list
{
	int		content;
	int		min;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int	ft_lstsize(t_list *lst);
int	ft_lst_sortcheck(t_list *head);
int	ft_lst_rev_sortcheck(t_list *head);
t_list	*ft_lstlast(t_list *lst);
int	ft_isdigit(char c);
int	ft_atoi(char *s);
int	ft_strlen(char *s);
int	ft_find_x(t_list *l, int x);
int	ft_find_min(t_list *l);
int	ft_digit_check(char *s);
int	ft_error_check(char **s);
int	ft_dup_check(char **s);
t_list	*ft_make_list(int a, char **s);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_swap(t_list **head, char c);
void	ft_push(t_list **i, t_list **j, char c);
void	ft_rotate(t_list **a, char c);
void	ft_rev_rotate(t_list **a, char c);
void	ft_sort_2(t_list **a);
void	ft_sort_3(t_list **a);
void	ft_sort_5(t_list **a, t_list **b, int x);
void	ft_sort(t_list **a, t_list **b);
#endif
