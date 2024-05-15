/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:10:44 by florian           #+#    #+#             */
/*   Updated: 2024/05/14 14:31:40 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/client.h"

int	check_server;

int main(int argc, char const **argv)
{
	struct sigaction	sa;
	int					i;
	sigset_t			mask;

	check_server = 0;
	sigemptyset(&mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = mask;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			send_signal(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
		send_signal(ft_atoi(argv[1]),'\0');
	}
	while (check_server != 2)
		pause();
	return (0);
}
