/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:13:58 by atangil           #+#    #+#             */
/*   Updated: 2023/09/18 15:38:07 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	kill_ch(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	feedback(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message get\n", 13);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = ((str[i] - 48) + (res * 10));
		i++;
	}
	return (res * sign);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	pid = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, feedback);
	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argv[2][i])
	{
		kill_ch(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	kill_ch(pid, '\0');
	return (0);
}
