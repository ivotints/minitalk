/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:14:40 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:34 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		write(1, &("0123456789"[nbr]), 1);
	return ;
}

void	ft_print_bit(int sig)
{
	static unsigned char	bit;
	static unsigned char	i;

	if (sig == SIGUSR1)
		i += (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

void	sigint_handler(int nic)
{
	(void)nic;
	ft_putstr_fd("\nCaught SIGINT signal (Ctrl+C)\n", 1);
	exit(0);
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("\033[31mError. Too much arguments\033[0m\n", 2);
		return (1);
	}
	pid = getpid();
	ft_putstr_fd("pid - ", 1);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, ft_print_bit);
		signal(SIGUSR2, ft_print_bit);
		signal(SIGINT, sigint_handler);
		pause ();
	}
	return (0);
}
