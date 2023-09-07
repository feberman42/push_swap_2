/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:32:19 by feberman          #+#    #+#             */
/*   Updated: 2023/09/07 14:53:05 by feberman         ###   ########.fr       */
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

typedef	enum e_stack {A, B}	t_stack;

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
	int		*arr;
	int		front;
	int		back;
	int		section_size;
	int		center;
}	t_stacks;

t_node			*create_node(int value);
void			list_add(t_node **list, t_node *node);
void			list_print(t_node **list);

void			ops_pa(t_stacks *stacks);
void			ops_pb(t_stacks *stacks);
void			ops_ra(t_stacks *stacks);
void			ops_rb(t_stacks *stacks);
void			ops_rra(t_stacks *stacks);
void			ops_rrb(t_stacks *stacks);

t_stacks		*create_stacks(int *arr);
int				arr_to_stack(t_stacks *stacks, int *arr);
int				get_index(int *arr, int value);
int				search_in_stack(t_node **stack, int value);
long int		*convert_to_bi(long int *bin, int nb);
int				move_cost(t_node *stack, t_node *find, long int *ignore);
long int		*get_beam(long int *beam, int i, int front, int back);
int				beam_cost(long int *beam, t_stacks *stacks, t_stack stack);
long int		*ref_to_beam(long int *beam, int back, int front);
int				in_beam(long int nb, long int *beam);
long int		*create_ignore(void);
void			rotate_to(t_stacks *stacks, t_stack stack, int value);
int				last_sorted_front(t_stacks *stacks);
int				last_sorted_back(t_stacks *stacks);
void			sorted_precheck(t_stacks *stacks);
int				get_section_size(t_stacks *stacks);
int				index_to_push(t_stacks *stacks, int index, int i);
void			evaluate_index(int index, t_stacks *stacks, int i);
long int		*search_beam(t_stacks *stacks, t_stack stack);
void			process_beam(long int *beam, t_stacks *stacks, t_stack stack);
int				find_insertion_point(t_stacks *stacks);
void			final_push(t_stacks *stacks);
int				presort(t_stacks *stacks);
int				sort(t_stacks *stacks);
void			*free_split(char **split, int size);
void			free_list(t_node **node);
void			free_stacks(t_stacks *stacks);
void			*error_ptr(void);
int				error_int(void);

int				*create_array(int argc, char *argv[]);
int				populate_arr(int argc, char *argv[], int *arr);
void			sort_arr(int *arr);
int				has_doubles(int *arr);
char			**ps_split(const char *s);
int				check_arg(char *arg);
int				my_pow(int base, int exp);

int				count_arguments(int argc, char *argv[]);
int				count_words(const char *s);
int				wordlen(const char *s);
int				split_string(char **split, const char *s, int wc);

void			print_beam(long int *beam);

#endif