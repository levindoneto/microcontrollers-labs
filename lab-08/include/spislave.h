/*
  spislave.h: Library for implementing an SPI slave in software.
  
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

#ifndef _SPISLAVE_H_
#define _SPISLAVE_H_

// Use IO4 as SCLK
class SclkSlave
{
	int fd;
	
	public:
	
	SclkSlave(void);
	~SclkSlave(void);
	void waitRise(void);
};
 
// Use IO5 as MOSI
class MosiSlave
{
	int fd;
	
	public:
	
	MosiSlave(void);
	~MosiSlave(void);
	int sample(void);

};

// Use IO7 as #SS
class SsSlave
{
	int fd;
	
	public:
	
	SsSlave(void);
	~SsSlave(void);
	int selected(void);
};

#endif
