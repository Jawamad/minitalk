/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:32:13 by florian           #+#    #+#             */
/*   Updated: 2024/05/15 16:29:41 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

int	main(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	sigemptyset(&mask);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = mask;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
