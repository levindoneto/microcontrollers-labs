/*
  spi_slave_rx.c: Receives a string using an SPI bus implemented in software.
  
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

#include <iostream>

#include <spislave.h>
	
int main(int argc,char *argv[])
{
	SclkSlave sclk;
	MosiSlave mosi;
	SsSlave ss;
	
#ifdef DEBUG
	std::cerr << "Waiting to be selected...";
	std::cerr.flush();
#endif

	while(!ss.selected());

#ifdef DEBUG	
	std::cerr << "selected." << std::endl;
#endif
	
	while(ss.selected())
	{
		char c=0;
		for(int i=0;i < 8;i++)
		{
#ifdef DEBUG				
			std::cerr << "Waiting clock rise...";
			std::cerr.flush();
#endif
			sclk.waitRise();
#ifdef DEBUG
			std::cerr << "rose...";
			std::cerr.flush();
#endif			
			
			c=(c << 1) | mosi.sample(); // Assume MSBit first

#ifdef DEBUG
			std::cerr << "sampled." << std::endl;
#endif			
			
			if(!ss.selected()) break;
		}	
		std::cout << c;
		std::cout.flush();
	}

#ifdef DEBUG
	std::cerr << "Deselected." << std::endl;
#endif

	return 0;
}
