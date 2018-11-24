#include <fcntl.h>
#include <unistd.h>

#include <spislave.h>

/*
Use IO5 as MOSI
	gpio0 = MOSI (input)
	gpio18=1 (IO5 is input)
	gpio19=1 (pull-up)
	gpio66=0 (IO5 is GPIO)
*/
MosiSlave::MosiSlave(void)
{
	fd=open("/sys/class/gpio/gpio0/value",O_RDWR);
}

MosiSlave::~MosiSlave(void)
{
	close(fd);
}

int MosiSlave::sample(void)
{
	char mosi;
	
	lseek(fd,0,SEEK_SET);
	read(fd,&mosi,sizeof(mosi));
	
	return (mosi != '0');
}	
