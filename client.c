/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:39:43 by lburkins          #+#    #+#             */
/*   Updated: 2024/05/03 14:29:25 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	send_signal(int pid, unsigned char c)
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

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (msg[i])
		{
			send_signal(pid, (unsigned char)msg[i]);
			i++;
		}
		send_signal(pid, '\0');
	}
	else
		ft_printf("Error: invalid input\n");
	return (0);
}
