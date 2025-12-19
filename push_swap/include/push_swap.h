/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:38:47 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 16:54:07 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct stack
{
	int				index;
	int				value;
	int				push_cost;
	int				is_cheapest;
	int				is_above_median;
	struct stack	*target;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

int		push_swap(int argc, char *argv[]);
int		can_split(char *str);
char	**split_num(char *s, char c);
int		init_stack(t_stack **a, char *argv[]);
int		has_err(char *argv[]);
long	ft_atol(char *str);
void	free_split_array(char **array);
int		print_err(void);
int		ft_isdigit(int c);
int		can_join_split(char *argv[]);
char	**join_n_split(char *argv[]);
int		sorted(t_stack *a);
void	sort_stack(t_stack **a, t_stack **b);
int		len_stack(t_stack *a);
t_stack	*get_last_node(t_stack *node);
void	update_index(t_stack *stack);
t_stack	*get_min(t_stack *stack);
t_stack	*get_max(t_stack *stack);
void	update_a(t_stack *a, t_stack *b);
void	move_cheapest_a_to_b(t_stack **a, t_stack **b);
void	update_b(t_stack *a, t_stack *b);
void	move_cheapest_b_to_a(t_stack **a, t_stack **b);
void	free_stack(t_stack **a);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
t_stack	*get_cheapest(t_stack *stack);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif