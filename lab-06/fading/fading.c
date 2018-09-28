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
    // Set duty cycle to zero
    write(fd,"0\n",2);
    
    // Enable it
    pputs("/sys/class/pwm/pwmchip0/pwm1/enable","1");

    // 1.000.000 nanoseconds = 1 milisecond
    // 100.000 nanoseconds = 0,1 milisecond
    for(i=0;i < 1000000;i+=100000)
    {
        // Every 0.1ms
        lseek(fd,0,SEEK_SET);
        // Write i as an integer into the str buffer
        snprintf(str,sizeof str,"%d\n",i);
        // Write the buffer into the duty cycle file
        write(fd,str,strlen(str));

        printf("%d\n",i);
        sleep(1);
    }
    
    close(fd);
    // Deactivate PWM
    pputs("/sys/class/pwm/pwmchip0/pwm1/enable","0");        
   
    return 0;
}
