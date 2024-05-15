/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:03:56 by florian           #+#    #+#             */
/*   Updated: 2024/05/15 16:31:47 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../printf/ft_printf.h"

/* server.c */

/* signal.c */
void	handle_signal(int sig, siginfo_t *info, void *context);
void	print_msg(siginfo_t *info, char **msg);

/* utils.c */
char	*complt_msg(char current_char, char *msg);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif