/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:22:53 by irifarac          #+#    #+#             */
/*   Updated: 2024/05/14 14:27:40 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int counter, char **str)
{
	pid_t	pid_server;
	int		position;

	if (counter == 3)
	{
		pid_server = ft_atoi(str[1]);
		if (pid_server <= 0)
		{
			ft_putstr(2, "PID invalido\n");
			return (0);
		}
		position = 0;
		while (*(*(str + 2) + position))
		{
			sign_handler(pid_server, *(*(str + 2) + position));
			position++;
		}
	}
	else
		ft_putstr(2, "Numero de argumentos incorrecto\n");
	return (0);
}

void	sign_handler(int pid_server, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c >> bit & 1)
		{
			if (kill(pid_server, SIGUSR1) < 0)
				exit(1);
		}
		else
		{
			if (kill(pid_server, SIGUSR2) < 0)
				exit(1);
		}
		if (usleep(250) < 0)
			exit(1);
	}
}
