#include <fcntl.h>
#include <unistd.h>

#include <spislave.h>

/*
Use IO9 as #SS
	gpio4 = #SS (input)
	gpio22=1 (IO9 is input
	gpio23=1 (pull-up)
	gpio70=0 (IO9 is GPIO)
*/
SsSlave::SsSlave(void)
{
	fd=open("/sys/class/gpio/gpio4/value",O_RDONLY);
}

SsSlave::~SsSlave(void)
{
	close(fd);
}

int SsSlave::selected(void)
{
	char ss_;

	lseek(fd,0,SEEK_SET);
	read(fd,&ss_,sizeof(ss_));

	return (ss_ == '0');
}	
