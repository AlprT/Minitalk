/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:27:10 by atangil           #+#    #+#             */
/*   Updated: 2023/09/18 12:12:05 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	printpid(int pid)
{
	if (pid >= 10)
		printpid(pid / 10);
	write(1, &"0123456789"[pid % 10], 1);
}

void	ft_printpid(int pid)
{
	write(1, "PID : ", 6);
	printpid(pid);
	write(1, "\n", 1);
}

void	get_bit(int sig)
{
	static int	i = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c += 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	ft_printpid(getpid());
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
		pause();
	return (0);
}
