/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:33:55 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/26 13:23:26 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || !s->head || !s->head->next)
		return ;
	first = s->head;
	second = s->head->next;
	first->next = second->next;
	second->next = first;
	s->head = second;
}

void	sa_sb_ss(t_stack *s1, t_stack *s2, char s_name)
{
	if (!ft_strchr("abs", s_name))
		return ;
	if (s_name != 's')
	{
		if (!s1 || !s1->head || !s1->head->next)
			return ;
		ft_swap(s1);
		ft_printf("s%c\n", s_name);
		return ;
	}
	if (!s1 || !s2 || !s1->head || !s1->head->next || !s2->head \
		|| !s2->head->next)
		return ;
	ft_swap(s1);
	ft_swap(s2);
	ft_printf("ss\n");
}

static void	ft_push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!dst || !src || !src->head)
		return ;
	tmp = src->head->next;
	src->head->next = dst->head;
	dst->head = src->head;
	src->head = tmp;
	src->size--;
	dst->size++;
}

void	pa_pb(t_stack *a, t_stack *b, char s_name)
{
	if (!ft_strchr("ab", s_name) || !a || !b)
		return ;
	if (s_name == 'a')
	{
		if (!b->head)
			return ;
		ft_push(a, b);
		ft_printf("pa\n");
	}
	else
	{
		if (!a->head)
			return ;
		ft_push(b, a);
		ft_printf("pb\n");
	}
}
