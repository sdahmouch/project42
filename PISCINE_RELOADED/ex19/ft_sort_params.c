/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:27:08 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/03 18:36:26 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_swap(char **argv, int a, int b)
{
	char *tmp;

	tmp = argv[a];
	argv[a] = argv[b];
	argv[b] = tmp;
}

void	ft_putstr(char **str)
{
	int	a;
	int	b;

	a = 1;
	while (str[a] != '\0')
	{
		b = 0;
		while (str[a][b])
		{
			ft_putchar(str[a][b]);
			b++;
		}
		a++;
		ft_putchar('\n');
	}
}

int		ft_sort_params(char **argv)
{
	int	a;
	int	b;
	int	c;

	a = 1;
	while (argv[a])
	{
		b = 1;
		while (argv[b] != 0)
		{
			c = 0;
			while (argv[a][c] == argv[b][c]
					&& argv[a][c] != '\0' && argv[b][c] != '\0')
				c++;
			if (argv[a][c] < argv[b][c])
				ft_swap(argv, a, b);
			b++;
		}
		a++;
	}
	ft_putstr(argv);
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argc;
	ft_sort_params(argv);
	return (0);
}
