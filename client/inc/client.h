/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:35:47 by florian           #+#    #+#             */
/*   Updated: 2024/05/14 14:07:01 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H


# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "../../printf/ft_printf.h"

extern int	check_server;
/* client.c */

/* signal.c */
void	send_signal(int pid, unsigned char character);
void	handle_signal(int sig, siginfo_t *info, void *context);

/* utils.c */
int		ft_atoi(const char *nptr);

#endif