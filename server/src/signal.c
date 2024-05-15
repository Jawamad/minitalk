/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:57:27 by florian           #+#    #+#             */
/*   Updated: 2024/05/15 16:31:34 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;
	static char				*msg;

	(void) context;
	if (!msg)
		msg = ft_calloc(1, 1);
	current_char |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			print_msg(info, &msg);
		else
			msg = complt_msg(current_char, msg);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

void	print_msg(siginfo_t *info, char **msg)
{
	printf("%s\n",*msg);
	free(*msg);
	*msg = NULL;
	usleep(50);
	kill(info->si_pid, SIGUSR2);
}

