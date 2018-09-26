/*
  inttst.c: Receives an interrupt on Galileo Gen2 IO4.
  
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
#include <poll.h>
#include <stdio.h>
#include <unistd.h>

#include <galileo2io.h>

int main(int argc,char * argv[])
{
        unsigned char c;
        struct pollfd pfd;

        //Verifica IO4
        if((pfd.fd=open("/sys/class/gpio/gpio6/value",O_RDONLY)) < 0)
        {
                perror("Opening gpio6:");
                return -1;
        }

        /* Clear old values */
        read(pfd.fd,&c,1);

        pfd.events=POLLPRI;

        puts("Waiting for interrupt...");

        pputs("/sys/class/gpio/gpio6/edge","both");

        poll(&pfd,1,-1);
        
        lseek(pfd.fd,0,SEEK_SET);
        read(pfd.fd,&c,1);
        
        pputs("/sys/class/gpio/gpio6/edge","none");

        close(pfd.fd);
        return 0;
}
