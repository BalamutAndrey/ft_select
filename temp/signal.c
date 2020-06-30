/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 11:46:52 by eboris            #+#    #+#             */
/*   Updated: 2020/03/08 12:50:22 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdint.h>
#include <termcap.h>
#include <termios.h>
#include <stdlib.h>
#include <fcntl.h>

void	setsignal(void);
void	sl_init_screen(int a);
void	sl_refresh(int a);
void	sl_abort(int a);

// gcc signal.c -Wall -Wextra -Werror -lncurses -ltermcap

int		main(void)
{
	uint64_t		buff;
	char			*nameterm;
	int				fd;
	struct termios	term;

	nameterm = getenv("TERM");
	tgetent(NULL, nameterm);

	fd = open(ttyname(0), O_RDWR | O_NDELAY);
	tcgetattr(fd, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_oflag &= ~(OPOST);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(fd, TCSANOW, &term);

	setsignal();
	while ((read(0, &buff, 16)) != 0)
	{
		if (buff == 0x1B)
			printf("Нажата кнопка Escape\n");
		else if (buff == 0x20)
			printf("Нажата кнопка Space\n");
		else if (buff == 0x415B1B)
			printf("Нажата кнопка Up\n");
		else if (buff == 0x425B1B)
			printf("Нажата кнопка Down\n");
		else if (buff == 0x435B1B)
			printf("Нажата кнопка Right\n");
		else if (buff == 0x445B1B)
			printf("Нажата кнопка Left\n");
		else if (buff == 0xA)
			printf("Нажата кнопка Enter\n");
		else if (buff == 0x7F)
			printf("Нажата кнопка BackSpace\n");
		else if (buff == 0x7E335B1B)
			printf("Нажата кнопка Delete\n");
		else
			printf("Нажата неизвестная кнопка, %llx\n", buff);
		buff = 0;
	}
}

void	setsignal(void)
{
	signal(SIGWINCH, sl_init_screen);
	signal(SIGCONT, sl_refresh);
	signal(SIGINT, sl_abort);
	signal(SIGQUIT, sl_abort);
	signal(SIGABRT, sl_abort);
	signal(SIGKILL, sl_abort);
	signal(SIGTERM, sl_abort);
	signal(SIGSTOP, sl_abort);
}

void	sl_init_screen(int a)
{
	(void)a;
	printf("\nИзменился размер терминала!\n");
}

void	sl_refresh(int a)
{
	(void)a;
	printf("\nПродолжение остановленного процесса!\n");
}

void	sl_abort(int a)
{
	(void)a;
	printf("\nВыход!\n");
}
