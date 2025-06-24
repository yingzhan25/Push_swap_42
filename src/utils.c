/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:34:14 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/24 16:13:46 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_new_node(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = nb;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	ft_free_stack(t_stack *s)
{
	t_node	*tmp;
	while (s->head)
	{
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
}

int	ft_is_sorted(t_stack *s)
{
	t_node	*tmp;

	tmp = s->head;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);;
	return(1);
}