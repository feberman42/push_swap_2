/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:32:19 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 16:34:36 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

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
	SA,
	SB,
	SS
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
	int		*arr;
}	t_stacks;

t_node			*create_node(int value);
void			list_add(t_node **list, t_node *node);

void			ops_pa(t_stacks *stacks);
void			ops_pb(t_stacks *stacks);
void			ops_ra(t_stacks *stacks);
void			ops_rb(t_stacks *stacks);
void			ops_rra(t_stacks *stacks);
void			ops_rrb(t_stacks *stacks);
void			ops_rr(t_stacks *stacks);
void			ops_rrr(t_stacks *stacks);
void			ops_sa(t_stacks *stacks);
void			ops_sb(t_stacks *stacks);
void			ops_ss(t_stacks *stacks);
void			do_operation(char *ops, t_stacks *stacks);
int				check(t_stacks *stacks);

int				*create_array(int argc, char *argv[]);
int				populate_arr(int argc, char *argv[], int *arr);
void			sort_arr(int *arr);

t_stacks		*create_stacks_bonus(int *arr);
int				arr_to_stack(t_stacks *stacks, int *arr);
int				has_doubles(int *arr);
char			**ps_split(const char *s);
int				check_arg(char *arg);
int				count_arguments(int argc, char *argv[]);
int				count_words(const char *s);
int				wordlen(const char *s);
int				split_string(char **split, const char *s, int wc);

void			*free_split(char **split, int size);
void			free_list(t_node **node);
void			free_bonus(t_stacks *stacks);

void			error(t_stacks *stacks, char *ops);

#endif