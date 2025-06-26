/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:23:25 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/25 20:27:33 by yingzhan         ###   ########.fr       */
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

void	get_new_index_chunk(int *arr, t_stack *s)
{
	int		i;
	t_node	*tmp;

	tmp = s->head;
	while (tmp)
	{
		i = 0;
		while (i < CHUNK_SIZE)
		{
			if (tmp->index == arr[i])
			{
				tmp->index = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	*get_sorted_array(t_stack *s)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * s->size);
	if (!arr)
	{
		ft_error();
		return(NULL);
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
	get_new_index(arr, a);
	return (arr);
}

void	get_sorted_chunk(int **c, t_stack *s, int max, int min)
{
	int	i;
	t_node	*node;

	node = s->head;
	i = 0;
	while (i < CHUNK_SIZE)
	{
		if (node->index >= min && node->index <= max)
		{
			c[i] = node->index;
			i++;
		}
		node = node->next;
	}
	bubble_sort(c, CHUNK_SIZE);
	get_new_index_chunk(c, s);
}

void	pb_chunk(t_stack *a, t_stack *b, int max, int min)
{
	int	pushed;
	int	val;
	t_node	*node;

	pushed = 0;
	while (pushed < CHUNK_SIZE && a->size > 0)
	{
		if (a->head->index >= min && a->head->index <= max)
		{
			val = a->head->index;
			pa_pb(a, b, 'b');
			pushed++;
			if (val < (max + min)/2 && b->head > 1)
				ra_rb_rr(b, NULL, 'b');
		}
		else
			ra_rb_rr(a, NULL, 'a');
	}
}

void	ft_chunk_sort(t_stack *a, t_stack *b)
{
	int	*arr;
	int	*chunk[CHUNK_SIZE];
	int	nb_chunk;
	int	max_chunk;
	int	min_chunk;
	int	i;

	arr = get_sorted_array(a);
	if (!arr)
		return ;
	nb_chunk = (a->size + CHUNK_SIZE - 1)/CHUNK_SIZE;
	i = 0;
	while(i < nb_chunk)
	{
		min_chunk = arr[i * CHUNK_SIZE];
		if (i != nb_chunk - 1)
			max_chunk = arr[(i + 1) * CHUNK_SIZE - 1];
		else
			max_chunk = arr[a->size - 1];
		get_sorted_chunk(&chunk, a, max_chunk, min_chunk);
		pb_chunk(a, b, max_chunk, min_chunk);
		i++;
	}
	free(arr);
}