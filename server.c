/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:20:08 by lburkins          #+#    #+#             */
/*   Updated: 2024/05/03 15:26:44 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	print_msg(char **received_msg)
{
	ft_printf("%s\n", *received_msg);
	free(*received_msg);
	*received_msg = NULL;
}

char	*join_chars(char *msg, char c)
{
	char	*full_msg;
	char	add_c[2];

	if (!msg)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	add_c[0] = c;
	add_c[1] = '\0';
	full_msg = ft_strjoin(msg, add_c);
	if (!full_msg)
	{
		free(msg);
		ft_putstr_fd("Error in strjoin\n", 2);
		exit(1);
	}
	free(msg);
	return (full_msg);
}

void	handle_signal(int signal)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static char				*received_msg;

	if (!received_msg)
	{
		received_msg = ft_strdup("");
		if (received_msg == NULL)
			exit(1);
	}
	if (signal == SIGUSR1)
		c |= 1 << i;
	else
		c |= 0 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			print_msg(&received_msg);
		else
			received_msg = join_chars(received_msg, c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Lauren's Server PID is: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
