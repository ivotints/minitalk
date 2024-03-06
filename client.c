/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:14:36 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/27 16:40:42 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atou(char *str)
{
	int	res;

	res = 0;
	while (*str)
		res = (*(str++) - '0') + (res * 10);
	return (res);
}

void	ft_print_bite(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i++)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putstr_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
			if (!ft_isdigit(av[1][i++]))
				ft_putstr_error("Invalid pid\n");
		while (*av[2])
			ft_print_bite(ft_atou(av[1]), *(av[2]++));
	}
	else
		write(2, "\033[31mError. Wrong number of arguments\n\033[0m", 40);
	return (0);
}
