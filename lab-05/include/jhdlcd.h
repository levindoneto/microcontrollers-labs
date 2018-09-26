/*
  jhdlcd.h: Definitions for the JHD1214 RGB LCD
  
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

#ifndef JHDLCD_H
#define JHDLCD_H

enum LCD_ADDRESSES
{
        LCD_ADDR=	0x7c >> 1,
        BL_ADDR=	0xc4 >> 1
};

enum LCD_COMMANDS
{
        LCD_SCREENCLEAR=	0x01,
        LCD_CURSORRETURN=	0x02,  
        LCD_INPUTSET=		0x04,
        LCD_DISPLAYSWITCH=	0x08,
        LCD_SHIFT=		0x10,   
        LCD_FUNCTIONSET=	0x20,   
        LCD_CGRAMADDRSET=	0x40,  
        LCD_DDRAMADDRSET=	0x80
};

enum LCD_REGS
{
        LCD_C0=	0x80,
        LCD_RS=	0x40
};

enum LCD_INPUTSET_BITS
{
        LCD_ENTRYRIGHT=	0x00,
        LCD_ENTRYLEFT=	0x02, 
        LCD_INCREMENT=	0x01,
        LCD_DECREMENT=	0x00
};

enum LCD_DISPLAYSWITCH_BITS
{
        LCD_DISPLAYON=	0x04,
        LCD_DISPLAYOFF=	0x00,
        LCD_CURSORON=	0x02,  
        LCD_CURSOROFF=	0x00, 
        LCD_BLINKON=	0x01,   
        LCD_BLINKOFF=	0x00  
};

enum LCD_SHIFT_BITS
{
        LCD_SHIFTDISPLAY=	0x08,
        LCD_SHIFTCURSOR=	0x00, 
        LCD_SHIFTRIGHT=		0x04,  
        LCD_SHIFTLEFT=		0x00 
};

enum LCD_FUNCTIONSET_BITS
{
        LCD_8BITMODE=	0x10,
        LCD_4BITMODE=	0x00,    
        LCD_2LINE=	0x08,  
        LCD_1LINE=	0x00,   
        LCD_5x10DOTS=	0x04,
        LCD_5x7DOTS=	0x00
};

enum BL_REGS
{
        BL_RED=		0x04,
        BL_GREEN=	0x03,
        BL_BLUE=	0x02,
        BL_MODE1=	0x00,
        BL_MODE2=	0x01,
        BL_LEDOUT=	0x08
};

enum BL_MODE1_BITS
{	
        BL_AI2=		0x80,
        BL_AI1=		0x40,
        BL_AI0=		0x20,
        BL_SLEEP=	0x10,
        BL_SUB1=	0x08,
        BL_SUB2=	0x04,
        BL_SUB3=	0x02,
        BL_ALLCALL=	0x01
};

enum BL_MODE2_BITS
{	
        BL_DMBLNK=	0x20,
        BL_INVRT=	0x10,
        BL_0CH=		0x08,
        BL_OUTDRV=	0x04,
        BL_OUTNE1=	0x02,
        BL_OUTNE0=	0x01,
        BL_OUTNE_OFF=	0x00,
        BL_OUTNE_OUTDRV=0x01,
        BL_OUTNE_HIZ=	0x10
};

enum BL_LEDOUT_BITS
{	
        BL_BLUE_OFF=	0x00,
        BL_BLUE_FULL=	0x01,
        BL_BLUE_PWM=	0x02,
        BL_BLUE_GRPPWM=	0x03,
        
        BL_GREEN_OFF=	0x00 << 2,
        BL_GREEN_FULL=	0x01 << 2,
        BL_GREEN_PWM=	0x02 << 2,
        BL_GREEN_GRPPWM=0x03 << 2,
        
        BL_RED_OFF=	0x00 << 4,
        BL_RED_FULL=	0x01 << 4,
        BL_RED_PWM=	0x02 << 4,
        BL_RED_GRPPWM=	0x03 << 4
};
#endif
