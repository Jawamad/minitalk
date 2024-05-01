/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:35:47 by florian           #+#    #+#             */
/*   Updated: 2024/04/20 15:40:58 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "../../printf/ft_printf.h"


/* client.c */

/* signal.c */
void	send_signal(int pid, unsigned char character);

#endif