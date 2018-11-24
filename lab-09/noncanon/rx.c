/*
  rx.c: Serial reception in non-canonical mode.
  
  Copyright (c) 2016 Walter Fetter Lages <w.fetter@ieee.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    You can also obtain a copy of the GNU General Public License
    at <http://www.gnu.org/licenses>.

*/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fd;
	char s[256];
	int n;
	struct termios tty;
	
	if(argc != 2)
	{
		printf("Noncanonical mode reception\n");
		printf("\tUsage:\t%s <device>\n",argv[0]);
		return -1;
	}
	//Abre o /dev/ttySx
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		perror(argv[0]);
		return -errno;
	}
	//Pega a struct termio
	if(tcgetattr(fd,&tty))
	{
		perror(argv[0]);
		return -errno;
	}	
	//Seta a mesma velocidade para ambos
	if(cfsetspeed(&tty,B9600))
	{
		perror(argv[0]);
		return -errno;
	}	        
	//Ajusta o termio para a estrutura não-canônica
	cfmakeraw(&tty);
	//Seta para que as alterações ocorram imediatamente
        if(tcsetattr(fd,TCSANOW,&tty))
	{
		perror(argv[0]);
		return -errno;
	}
	for(;;)
	{
		//Lê o buffer
		if((n=read(fd,s,255))==-1)
		{
			perror(argv[0]);
			return -errno;
		}
		s[n]='\0';
		//Printa a string do buffer
		printf("%s",s);
		fflush(stdout);
	}

	if(close(fd))
	{
		perror(argv[0]);
		return -errno;
	}
	
	return 0;
}
