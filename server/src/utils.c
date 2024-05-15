/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:43:20 by florian           #+#    #+#             */
/*   Updated: 2024/05/13 17:46:28 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

/* todo desc */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}

/* todo desc */
char	*complt_msg(char current_char, char *msg)
{
	int		i;
	int		len;
	char	*msg_complt;

	
	len = ft_strlen(msg);
	msg_complt = ft_calloc(len + 2, sizeof(char));
	ft_memcpy(msg_complt, msg, len);
	free(msg);
	i = 0;
	while (msg_complt[i])
		i++;
	msg_complt[i++] = current_char;
	msg_complt[i] = '\0';
	return msg_complt;
}

/* todo desc */
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	unsigned int	tsize;
	unsigned int	i;

	tsize = nmemb * size;
	if (!nmemb || !size)
		return (malloc(0));
	if (tsize / size != nmemb || tsize / nmemb != size)
		return (0);
	res = malloc(tsize);
	if (res)
	{
		i = 0;
		while (i < tsize)
		{
			res[i] = '\0';
			i++;
		}
	}
	return ((void *)res);
}
