/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:43 by florian           #+#    #+#             */
/*   Updated: 2024/05/14 16:07:02 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;
	
	i = 8;
	temp_char = character;
	while (i > 0)
	{
		while(check_server == 1)
			pause();
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		check_server = 1;
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sig == SIGUSR1)
		check_server = 0;
	if (sig == SIGUSR2)
	{
		printf("The server receive the message 👍\n");
		check_server = 2;
	}
}