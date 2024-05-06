/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:39:43 by lburkins          #+#    #+#             */
/*   Updated: 2024/05/06 16:25:35 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	send_signal(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	receive_signal(int signal, siginfo_t *info, void *context)
{
	(void)info;//not sure this is best way to handle??
	(void)context;//not sure this is best way to handle??
	if (signal == SIGUSR1)
	{
		ft_printf("Server: message received 👌\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	client_sa;
	int					pid;
	char				*msg;
	int					i;

	i = 0;
	client_sa.sa_flags = SA_SIGINFO;
	client_sa.sa_sigaction = receive_signal;
	sigemptyset(&client_sa.sa_mask);
	sigaction(SIGUSR1, &client_sa, NULL);
	if (argc == 3)
	{
		ft_printf("test\n");
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (msg[i])
		{
			send_signal(pid, (unsigned char)msg[i]);
			i++;
		}
		send_signal(pid, '\0');
		pause();
	}
	else
		ft_printf("Error: invalid input. Use format ./client <PID> <Message>\n");
	return (0);
}
