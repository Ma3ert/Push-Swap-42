/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:26:53 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/14 15:12:27 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 11

# define MIN_INT "-2147483648"
# define MAX_INT "2147483647"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct d_pivot
{
	int	min;
	int	max;
	int	value;
}				t_pivot;

typedef struct d_info
{
	int	a_len;
	int	b_len;
	int	a_mid;
	int	b_mid;
	int	a_dis;
	int	b_dis;
	int	a_index;
	int	b_index;
	int	min_a;
	int	max_a;
	int	min_b;
	int	max_b;
	int	min;
}				t_info;

typedef struct d_list
{
	int				distance;
	int				n_index;
	int				push;
	int				p_index;
	int				index;
	int				len;
	int				content;
	struct d_list	*next;
}				t_list;

int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		arg_validation(char **av);
int		is_num(char *str);
void	ft_putstr(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		count_d(const char *s, char c);
void	free_t(char **str);

t_list	*pop_node(t_list **head);
void	add_node(t_list **old_node, int content);
void	add_first_node(t_list **first_node, int content);
void	print_stack(t_list *stack);
void	free_stack(t_list *stack);

void	swap_element(t_list *first_element, char *str);
void	push_element(t_list **from_list, t_list **to_list, char *str);
void	rotate_element(t_list **stack, char *str);
void	reverse_rotate(t_list **stack, char *str);

int		ft_max_value(t_list *stack);
int		ft_min_value(t_list *stack);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		element_count(t_list *stack);

void	re_index(t_list *stack);
double	index_finder(t_list *stack, int value);
t_list	*find_element(t_list *stack, int index);

int		ft_lis(t_list *stack);
void	ft_lis_lenght(t_list *i, t_list *j);
int		max_len(t_list *tmp);
int		ft_markup(t_list *head);
void	push_lis(t_list **stack_a, t_list **stack_b, int i);
void	rotate_decision(t_list **stack, int value, int dec, char *str);
void	top_element(t_list **stack, int value);
void	sort_element(t_list **stack_a, t_list **stack_b, int n);

t_list	*best_position(t_list *stack_a, int content);
void	move_best_element(t_list **a, t_list **b, t_list *node_b, t_info *info);
t_list	*best_element(t_list *stack_a, t_list *stack_b, t_info *info);
int		element_count(t_list *stack);
void	top_element(t_list **stack, int value);
void	distance_calcul(t_list *node_a, t_list *node_b, t_info *info);
t_list	*ft_distance(t_list *stack_b, t_info *info);

void	rr_decision(t_list **stack_a, t_list **stack_b, t_info *info);
void	rrr_decision(t_list **stack_a, t_list **stack_b, t_info *info);
void	double_rotate(t_list **a, t_list **b, t_info *info, int dec);
void	ft_sort(t_list **stack_a, t_list **stack_b);

void	apply_instruction(t_list **stack_a, t_list **stack_b, char *str);
void	double_instruction(t_list **stack_a, t_list **stack_b, char *str);
int		check_sort(t_list *stack_a);
void	check_instruction(t_list **stack_a, t_list **stack_b);

char	*ft_strdupi(const char *s1, int l);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_new_line(char *buffer);
char	*get_rest(char *buffer);
char	*get_new_buffer(char *rest, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*get_buffer(char *buffer, int fd, char *rest, int nbyte);

char	**adjust_arg(char **av, int *ac);
char	**join_arg(char **s1, char *s2);
int		string_count(char **str);

void	sort_five_less(t_list **stack_a, t_list **stack_b, int n);
void	sort_three(t_list **stack);

#endif