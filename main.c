/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:58:03 by msireau           #+#    #+#             */
/*   Updated: 2015/12/13 18:15:43 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#include <stdio.h>

#define BUF_SIZE 4096

int		ft_checktetri(char *buf)
{
	int		i;
	int		a;

	i = 0;
	while (buf[i])
	{
		a = 0;
		while (buf[i] != '\n')
		{
			if (a > 4 || (buf[i] != '.' && buf[i] != '#'))
			{
				ft_putstr("error");
				return(0);
			}
			a++;
			i++;
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		fd;
	int		ret;

	char	buf[BUF_SIZE + 1];
	fd = open("valid_sample.fillit", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open () error");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ft_putnbr(ft_checktetri(buf));
	if (close(fd) == -1)
	{
		ft_putstr("close () failed");
		return (1);
	}
	return (0);
}
