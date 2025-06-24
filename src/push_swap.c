/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:34:00 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/24 15:32:53 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	bits_mapping(t_stack *s)
{
	unsigned int	u;
	t_node			*tmp;

	tmp = s->head;
	while (tmp)
	{
		u = (unsigned int)tmp->value;
		u ^= 0x80000000;
		tmp->value = (int)u;
		tmp = tmp->next;
	}
}

static int	count_bits(t_stack *s)
{
	int		max_bits;
	int		bits;
	unsigned int	u;
	t_node	*tmp;

	max_bits = 0;
	tmp = s->head;
	while (tmp)
	{
		u = (unsigned int)tmp->value;
		bits = 0;
		while (u != 0)
		{
			u >>= 1;
			bits++;
		}
		if (bits > max_bits)
			max_bits = bits;
		tmp = tmp->next;
	}
	return (max_bits);
}

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		size;
	int		i;
	int		j;

	bits_mapping(a);
	max_bits = count_bits(a);
	i = -1;
	size = a->size;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((a->head->value >> i) & 1)
				ra_rb_rr(a, NULL, 'a');
			else
				pa_pb(a, b, 'b');
		}
		while (b->size)
			pa_pb(a, b, 'a');
	}
}

void	ft_sort_3(t_stack *a)
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