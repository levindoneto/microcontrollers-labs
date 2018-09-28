/*
  fading.c: Dimmers a LED on Galileo Gen2 IO3 using PWM.
  
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
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <galileo2io.h>

int main(int argc,char * argv[])
{
        int fd;
        int i;
        char str[80];

        pputs("/sys/class/pwm/pwmchip0/device/pwm_period","1000000");
        
        if((fd=open("/sys/class/pwm/pwmchip0/pwm1/duty_cycle",O_WRONLY)) < 0)
        {
                perror("Opening duty_cycle:");
                return -1;
        }
        //Seta duty cycle pra zero
        write(fd,"0\n",2);
        
        //Dá enable
        pputs("/sys/class/pwm/pwmchip0/pwm1/enable","1");

        //1.000.000 nanossegundos = 1 milissegundo
        //100.000 nanossegundos = 0,1 milissegundo
        for(i=0;i < 1000000;i+=100000)
        {
                //A cada 0,1 milis
                lseek(fd,0,SEEK_SET);
                //Escreve i no formato integer no buffer str
                snprintf(str,sizeof str,"%d\n",i);
                //Escreve o buffer no arquivo do duuty-cycle
                write(fd,str,strlen(str));

                printf("%d\n",i);
                sleep(1);
        }
        
        close(fd);
        //Desabilita o pwm
        pputs("/sys/class/pwm/pwmchip0/pwm1/enable","0");        
       
        return 0;
}
