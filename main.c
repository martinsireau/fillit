/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:58:03 by msireau           #+#    #+#             */
/*   Updated: 2015/12/16 13:58:21 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft.h"

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
				ft_error();
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
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_error();
	if (fd == -1)
		ft_error();
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
