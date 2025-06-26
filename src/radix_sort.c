/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:34:00 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/26 13:35:50 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_new_index(int *arr, t_stack *s)
{
	int		i;
	t_node	*tmp;

	tmp = s->head;
	while (tmp)
	{
		i = 0;
		while (i < s->size)
		{
			if (tmp->value == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static int	index_mapping(t_stack *s)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * s->size);
	if (!arr)
		return (ft_error());
	i = 0;
	tmp = s->head;
	while (i < s->size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(arr, s->size);
	get_new_index(arr, s);
	free(arr);
	return (0);
}

static int	count_bits(t_stack *s)
{
	int				max_bits;
	int				bits;
	unsigned int	u;
	t_node			*tmp;

	max_bits = 0;
	tmp = s->head;
	while (tmp)
	{
		u = (unsigned int)tmp->index;
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

static void	radix_sort_b(t_stack *a, t_stack *b, int bits, int j)
{
	int	i;
	int	size;

	i = 0;
	size = b->size;
	while (i < size && j <= bits && !ft_is_sorted(a))
	{
		if (!b->head->index >> j & 1)
			ra_rb_rr(b, NULL, 'b');
		else
			pa_pb(a, b, 'a');
		i++;
	}
	if (ft_is_sorted(a))
	{
		while (b->size)
			pa_pb(a, b, 'a');
	}
}

int	ft_radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		size;
	int		i;
	int		j;

	if (index_mapping(a))
		return (1);
	max_bits = count_bits(a);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		size = a->size;
		while (++j < size && !ft_is_sorted(a))
		{
			if ((a->head->index >> i) & 1)
				ra_rb_rr(a, NULL, 'a');
			else
				pa_pb(a, b, 'b');
		}
		radix_sort_b(a, b, max_bits, i + 1);
	}
	return (0);
}
