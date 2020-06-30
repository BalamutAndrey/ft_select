/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:15:06 by eboris            #+#    #+#             */
/*   Updated: 2020/03/08 13:05:21 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termcap.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int	ft_putchar(int c)
{
//	write(1, &c, 1);
	(void)c;
	return (0);
}

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(0, &str[i], 1);
		i++;
	}
}

size_t		ft_strlen(const char *s)
{
	size_t cpt;

	cpt = 0;
	while (s[cpt])
		cpt++;
	return (cpt);
}

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int		main(void)
{
	char	*nameterm;

	nameterm = getenv("TERM");
	// printf("nameterm1 = %s", nameterm);
	tgetent(NULL, nameterm);

//init
//
// http://citforum.ru/operating_systems/linux_pg/lpg_05.shtml
//
// gcc tgetenv.c -Wall -Wextra -Werror -lncurses -ltermcap
//

	int		fd;
	struct termios	term;

	fd = open(ttyname(0), O_RDWR | O_NDELAY);
	tcgetattr(fd, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_oflag &= ~(OPOST);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(fd, TCSANOW, &term);



	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);


	ft_putstr_fd(tgetstr("us", NULL), 0);
	ft_putstr(" This is a text ");
	ft_putstr_fd(tgetstr("ue", NULL), 0);


	ft_putstr(" This is a text ");


	ft_putstr_fd(tgetstr("so", NULL), 0);
	ft_putstr(" This is a text ");
	ft_putstr_fd(tgetstr("se", NULL), 0);


	ft_putstr(" This is a text ");


	ft_putstr_fd(tgetstr("us", NULL), 0);
	ft_putstr_fd(tgetstr("so", NULL), 0);
	ft_putstr(" This is a text ");
	ft_putstr_fd(tgetstr("ue", NULL), 0);
	ft_putstr_fd(tgetstr("se", NULL), 0);


	ft_putstr("../libft/*");


	// IF EXIT ONLY!
	//ft_putstr_fd(tgetstr("te", NULL), 0);
	//ft_putstr_fd(tgetstr("ve", NULL), 0);


	// int lines;
	// int cols;
	// lines=tgetnum("li"); /* полосы терминала */
 	// cols=tgetnum("co"); /* колонки терминала */
	// printf("lines = %i, cols = %i", lines, cols);
	return (0);
}

