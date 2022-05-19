/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:50:42 by mabasset          #+#    #+#             */
/*   Updated: 2022/04/04 22:50:42 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	action(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 1;

	(void)context;
	if (sig == SIGUSR1)
		c |= 0;
	else
		c |= 1;
	if (i == 8)
	{
		i = 1;
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		return ;
	}
	c <<= 1;
	i++;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
