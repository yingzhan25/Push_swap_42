/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:22:55 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/26 13:38:28 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

int		ft_radix_sort(t_stack *a, t_stack *b);
void	ft_small_sort(t_stack *a, t_stack *b);
void	sa_sb_ss(t_stack *s1, t_stack *s2, char s_name);
void	pa_pb(t_stack *a, t_stack *b, char s_name);
void	ra_rb_rr(t_stack *s1, t_stack *s2, char s_name);
void	rra_rrb_rrr(t_stack *s1, t_stack *s2, char s_name);
t_node	*ft_new_node(int nb);
void	ft_free_stack(t_stack *s);
int		ft_is_sorted(t_stack *s);
int		ft_error(void);
void	bubble_sort(int *arr, int size);

#endif