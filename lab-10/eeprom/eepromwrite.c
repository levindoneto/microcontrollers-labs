/*
  eepromwrite.c: Write to eeprom using the /dev interface
  
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

#include <galileo2io.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("Write EEPROM\n");
		printf("\tUsage:\t%s <string>\n",argv[0]);
		return -1;
	}
	//Escreve o primeiro parâmetro na eeprom
	if(pputs("/sys/bus/i2c/devices/0-0054/eeprom",argv[1]) < 0)
	{
		perror(argv[0]);
		return errno;
	}
	
	return 0;
}
