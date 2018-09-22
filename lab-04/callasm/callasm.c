/*
  callasm.c: Calls assembly functions for sum and difference.
  
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

#include <stdio.h>
#include <stdlib.h>

#include <asmops.h>

int main(int argc,char *argv[])
{
	int a;
	int b;
	int s;
	int d;
	
	if(argc != 3)
	{
		printf("Usage:\n\t%s <int> <int>\n",argv[0]);
		return -1;
	}

	a=atoi(argv[1]);
	b=atoi(argv[2]);
	
	s=sum(a,b);
	d=diff(&a,&b);
	
	printf("%d+%d=%d\n%d-%d=%d\n",a,b,s,a,b,d);
	
	return 0;
}
