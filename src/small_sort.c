/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:21:41 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/26 13:22:18 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_sort_3(t_stack *a)
{
	t_node	*one;
	t_node	*two;
	t_node	*three;

	one = a->head;
	two = one->next;
	three = two->next;
	if (one->value < three->value && three->value < two->value)
	{
		rra_rrb_rrr(a, NULL, 'a');
		sa_sb_ss(a, NULL, 'a');
	}
	else if (two->value < one->value && one->value < three->value)
		sa_sb_ss(a, NULL, 'a');
	else if (three->value < one->value && one->value < two->value)
		rra_rrb_rrr(a, NULL, 'a');
	else if (two->value < three->value && three->value < one->value)
		ra_rb_rr(a, NULL, 'a');
	else if (three->value < two->value && two->value < one->value)
	{
		ra_rb_rr(a, NULL, 'a');
		sa_sb_ss(a, NULL, 'a');
	}
}

static int	find_min(t_stack *a)
{
	t_node	*tmp;
	int		size;
	int		min;

	size = a->size;
	tmp = a->head;
	min = tmp->value;
	while (size)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
		size--;
	}
	return (min);
}

void	ft_small_sort(t_stack *a, t_stack *b)
{
	int		min;
	int		size;

	if (a->size == 2)
		sa_sb_ss(a, NULL, 'a');
	else if (a->size == 3)
		ft_sort_3(a);
	else if (a->size <= 5)
	{
		size = a->size;
		while (size >= 4)
		{
			min = find_min(a);
			while (a->head->value != min)
				ra_rb_rr(a, NULL, 'a');
			pa_pb(a, b, 'b');
			size--;
		}
		ft_sort_3(a);
		while (b->size > 0)
			pa_pb(a, b, 'a');
	}
}
