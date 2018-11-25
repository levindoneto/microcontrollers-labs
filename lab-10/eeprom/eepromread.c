/*
  eepromread.c: Read from eeprom using the /dev interface
  
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
#include <stdio.h>
#include <unistd.h>

#include <galileo2io.h>

int main(int argc,char *argv[])
{
	char s[1024];
	//Vê se tem algo na eeprom
        if(pgets(s,sizeof s,"/sys/bus/i2c/devices/0-0054/eeprom") < 0)
        {
		perror(argv[0]);
		return errno;
	}
	//Escreve a mesma coisa na tela
        if(write(STDOUT_FILENO,s,sizeof s) < 0)
        {
		perror(argv[0]);
		return errno;
	}
	return 0;
}
