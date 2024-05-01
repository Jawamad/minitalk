/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:10:44 by florian           #+#    #+#             */
/*   Updated: 2024/04/25 15:13:33 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/client.h"

int main(int argc, char const **argv)
{
	if (argc == 2)
	{
		while (argv[2])
			send_signal(argv[1], argv[2]++);
	}
	signal(SIGUSR2, handle_signal);
	return (0);
}
