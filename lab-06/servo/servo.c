/*
  servo.c: Commands a radio-control servo on Galileo Gen2 IO3 using PWM.
  
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <galileo2io.h>

int main(int argc,char * argv[])
{
        int duty_cycle;
        double angle;
        char str[100];
        
        if(argc != 2)
        {
                puts("Usage: servo <angle in degrees>");
                return -1;
        }
        //Converte para radianos
        angle=atof(argv[1]) * M_PI/180.0;
        //Só aceita entre 180°/-180°
        if((angle > M_PI_2) || (angle < - M_PI_2))
        {
                puts("Out of range.");
                return -2;
        }
        //850.000 = usado para converter em frequência
        //1.500.000ns = 1.500 us = frequência do sentido anti-horário
        duty_cycle=angle/M_PI_2*850000+1500000;
        //Período de 20.000.000ns == 20ms
        pputs("/sys/class/pwm/pwmchip0/device/pwm_period","20000000");
        //Formata o duty cylce
        snprintf(str,sizeof str,"%d\n",duty_cycle);
        pputs("/sys/class/pwm/pwmchip0/pwm1/duty_cycle",str);
        pputs("/sys/class/pwm/pwmchip0/pwm1/enable","1");
        
        sleep(1);

        return 0;
}
