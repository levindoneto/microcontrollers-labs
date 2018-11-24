#include <fcntl.h>
#include <unistd.h>

#include <spislave.h>

/*
Use IO4 as SCLK, mode 0
	gpio6 = SCLK (input)
	gpio36=1 (IO4 is input)
	gpio37=0 (pull-down)
*/
SclkSlave::SclkSlave(void)
{
	fd=open("/sys/class/gpio/gpio6/value",O_RDONLY);
}

SclkSlave::~SclkSlave(void)
{
	close(fd);
}

void SclkSlave::waitRise(void)
{
	char sclk;
	
	do
	{
		lseek(fd,0,SEEK_SET);
		read(fd,&sclk,sizeof(sclk));
	} while(sclk != '0');
	
	do
	{
		lseek(fd,0,SEEK_SET);
		read(fd,&sclk,sizeof(sclk));
	} while(sclk == '0');
}	
