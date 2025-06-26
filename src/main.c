/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:33:20 by yingzhan          #+#    #+#             */
/*   Updated: 2025/06/25 20:27:59 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_not_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			if (!(i == 0 && (str[i] == '-' || str[i] == '+')))
				return (1);
		i++;
	}
	return (0);
}

static int	ft_overflow(char *str)
{
	long	nb;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	nb = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb + (str[i] - '0');
		if (sign == 1 && nb > INT_MAX)
			return(1);
		else if (sign == -1 && nb > (long)INT_MAX + 1)
			return(1);
		i++;
	}
	return (0);
}

static int	ft_input_invalid(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[++i])
	{
		if (ft_not_digit(s[i]))
			return (1);
		if (ft_overflow(s[i]))
			return (1);
		j = 0;
		while (++j < i)
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (1);
		}
	}
	return (0);
}

static int	ft_parse_stack(t_stack *s, int ac, char *av[])
{
	int		i;
	int		nb;
	t_node	*node;

	i = ac - 1;
	while (i >= 1)
	{
		nb = ft_atoi(av[i]);
		node = ft_new_node(nb);
		if (!node)
		{
			ft_free_stack(s);
			return (1);
		}
		node->next = s->head;
		s->head = node;
		s->size++;
		i--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){NULL, 0};
	b = (t_stack){NULL, 0};
	if (argc < 2)
		return (0);
	if (ft_input_invalid(argv) || ft_parse_stack(&a, argc, argv))
		exit(ft_error());
	if (!ft_is_sorted(&a))
	{
		if (a.size <= 5)
			ft_small_sort(&a, &b);
		else
		{
			ft_chunk_sort(&a, &b);
			ft_radix_sort(&a, &b);
		}
	}
	ft_free_stack(&a);
	return (0);
}
