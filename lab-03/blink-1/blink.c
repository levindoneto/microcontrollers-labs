/*
  blink.c: Blinks a LED on Galileo Gen2 IO13.
  
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

#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	char state='0';
	int fd;
	
	fd=open("/sys/class/gpio/gpio7/value",O_WRONLY);

	for(;;)
	{	
		lseek(fd,0,SEEK_SET);
		write(fd,&state,sizeof state);
		sleep(1);
		state^='0'^'1';
	}
	
	close(fd);
	
	return 0;
}
