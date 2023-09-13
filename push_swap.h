/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:32:19 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 10:16:14 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>// attention

# define BEAM_SIZE 10
# define BEAM_STOP 1000000000

typedef enum e_stack {A, B}	t_stack;
typedef enum e_ops 
{
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
	SA
}	t_ops;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stacks
{
	t_node	**a;
	t_node	**b;
	t_node	*operations;
	int		*arr;
	int		front;
	int		back;
	int		section_size;
	int		center;
}	t_stacks;

t_node			*create_node(int value);
void			list_add(t_node **list, t_node *node);

int				ops_pa(t_stacks *stacks, int mode);
int				ops_pb(t_stacks *stacks, int mode);
int				ops_ra(t_stacks *stacks, int mode);
int				ops_rb(t_stacks *stacks, int mode);
int				ops_rra(t_stacks *stacks, int mode);
int				ops_rrb(t_stacks *stacks, int mode);
int				ops_sa(t_stacks *stacks);

int				append_ops(t_stacks *stacks, t_ops ops);
void			put_ops_out(t_ops ops);
void			print_ops(t_stacks *stacks);
void			remove_ops(t_stacks *stacks, t_node *ops);

void			filter(t_stacks *stacks);
void			filter_useless_rotate(t_stacks *stacks);
void			filter_useless_reverse_rotate(t_stacks *stacks);
void			filter_double_rotate(t_stacks *stacks);
void			filter_double_reverse_rotate(t_stacks *stacks);

t_stacks		*create_stacks(int *arr);
int				arr_to_stack(t_stacks *stacks, int *arr);
int				get_index(int *arr, int value);
int				search_in_stack(t_node **stack, int value);
int				rotate_to(t_stacks *stacks, t_stack stack, int value);
void			move(t_stacks *stacks, t_stack stack, int moves);
int				last_sorted_front(t_stacks *stacks);
int				last_sorted_back(t_stacks *stacks);
void			sorted_precheck(t_stacks *stacks);
int				precheck(t_stacks *stacks);
void			set_section_size(t_stacks *stacks);
int				index_to_push(t_stacks *stacks, int index, int i);
int				evaluate_index(int index, t_stacks *stacks, int i);
void			look_back(\
					t_stacks *stacks, int *value_index, t_node **check, int i);
int				find_insertion_point(t_stacks *stacks);
void			final_push(t_stacks *stacks);
int				presort(t_stacks *stacks);
int				sort(t_stacks *stacks);
int				get_cost(t_stacks *stacks);
void			*free_split(char **split, int size);
void			free_list(t_node **node);
int				free_stacks(t_stacks *stacks);
void			free_ops(t_node *node);
void			*error_ptr(void);
int				error_int(void);

int				*create_array(int argc, char *argv[]);
int				populate_arr(int argc, char *argv[], int *arr);
void			sort_arr(int *arr);
int				has_doubles(int *arr);
char			**ps_split(const char *s);
int				check_arg(char *arg);
int				ft_abs(int value);

int				count_arguments(int argc, char *argv[]);
int				count_words(const char *s);
int				wordlen(const char *s);
int				split_string(char **split, const char *s, int wc);

#endif