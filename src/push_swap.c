/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:34:00 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/24 11:20:11 by yingzhan         ###   ########.fr       */
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