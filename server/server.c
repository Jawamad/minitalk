/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:32:13 by florian           #+#    #+#             */
/*   Updated: 2024/04/25 15:16:33 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

int	main()
{
	struct sigaction sa;

	ft_printf("%d", getpid());
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	return (0);
}

static void	action(int sig, siginfo_t *info, void *context)
{
	printf("test");
}


