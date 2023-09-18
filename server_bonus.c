/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:20:27 by atangil           #+#    #+#             */
/*   Updated: 2023/09/18 15:34:54 by atangil          ###   ########.fr       */
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

void	get_bit(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)(context);
	if (sig == SIGUSR1)
		c += 1;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = get_bit;
	sig.sa_flags = SA_SIGINFO;
	ft_printpid(getpid());
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		return (-1);
	while (1)
		pause();
	return (0);
}
