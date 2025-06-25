/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:34:00 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/25 15:16:23 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	get_new_index(int *arr, t_stack *s)
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
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static void	index_mapping(t_stack *s)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * s->size);
	if (!arr)
	{
		ft_error();
		return ;
	}
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

int	is_edgecase_start(t_stack *a, int i)
{
	t_node	*tmp;

	tmp = a->head;
	if (tmp->index >> i & 1)
	{
		tmp = a->head->next;
		while (tmp)
		{
			if (tmp->index >> i & 1)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int	is_edgecase_end(t_stack *a, int i)
{
	t_node	*lst;

	lst = a->head;
	while (lst->next)
	{
		if (lst->index >> i & 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		size;
	int		i;
	int		j;

	index_mapping(a);
	max_bits = count_bits(a);
	i = -1;
	size = a->size;
	while (++i < max_bits)
	{
		j = -1;
		if (is_edgecase_start(a, i))
		{
			ra_rb_rr(a, NULL, 'a');
			continue;
		}
		else if (is_edgecase_end(a, i))
			continue;
		while (++j < size)
		{
			if ((a->head->index >> i) & 1)
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