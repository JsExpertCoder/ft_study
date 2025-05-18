/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:01:41 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/18 22:06:06 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static bool	validate_operator(char *op)
{
	if (ft_strlen(op) > 1)
		return (false);
	if (*op == '+' || *op == '-' || *op == '/' || *op == '*' || *op == '%')
		return (true);
	return (false);
}

static int	operator_table(char op)
{
	if (op == '+')
		return (0);
	else if (op == '-')
		return (1);
	else if (op == '/')
		return (2);
	else if (op == '*')
		return (3);
	return (4);
}

int	main(int ac, char **av)
{
	int		operator;
	int		final_return;
	t_calc	functions[5];

	final_return = 0;
	if (ac == 4)
	{
		if (!validate_operator(av[2]))
		{
			ft_putstr("0\n");
			return (1);
		}
		functions[0] = &sum;
		functions[1] = &sub;
		functions[2] = &div_;
		functions[3] = &mult;
		functions[4] = &mod;
		operator = operator_table(av[2][0]);
		final_return = (*functions[operator])(ft_atoi(av[1]), ft_atoi(av[3]));
		write(1, "\n", 1);
	}
	return (final_return);
}
