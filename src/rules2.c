/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:36:21 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/23 15:35:13 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_stack *s)
{
	t_node	*last;
	t_node	*first;

	if (!s || !s->head || !s->head->next)
		return ;
	last = s->head;
	first = s->head;
	while (last->next)
		last = last->next;
	last->next = first;
	s->head = first->next;
	first->next = NULL;
}

void	ra_rb_rr(t_stack *s1, t_stack *s2, char s_name)
{
	if (!ft_strchr("abr", s_name))
		return ;
	if (s_name != 'r')
	{
		if (!s1 || !s1->head || !s1->head->next)
			return ;
		ft_rotate(s1);
		ft_printf("r%c\n", s_name);
		return ;
	}
	if (!s1 || !s2 || !s1->head || !s1->head->next || !s2->head \
		|| !s2->head->next)
		return ;
	ft_rotate(s1);
	ft_rotate(s2);
	ft_printf("rr\n");
}

static void	ft_reverse_rotate(t_stack *s)
{
	t_node	*lst_second;
	t_node	*last;

	if (!s || !s->head || !s->head->next)
		return ;
	lst_second = s->head;
	while (lst_second->next->next)
		lst_second = lst_second->next;
	last = lst_second->next;
	last->next = s->head;
	s->head = last;
	lst_second->next = NULL;
}

void	rra_rrb_rrr(t_stack *s1, t_stack *s2, char s_name)
{
	if (!ft_strchr("abr", s_name))
		return ;
	if (s_name != 'r')
	{
		if (!s1 || !s1->head || !s1->head->next)
			return ;
		ft_reverse_rotate(s1);
		ft_printf("rr%c\n", s_name);
		return ;
	}
	if (!s1 || !s2 || !s1->head || !s1->head->next || !s2->head \
		|| !s2->head->next)
		return ;
	ft_reverse_rotate(s1);
	ft_reverse_rotate(s2);
	ft_printf("rrr\n");
}