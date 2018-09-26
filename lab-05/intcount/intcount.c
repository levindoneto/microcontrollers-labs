#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include <galileo2io.h>

static volatile int run=1;

void quit(int signal)
{
        run=0;
}

int main(int argc,char * argv[])
{
        unsigned char c;
        
        /*A estrutura pollpd se dá por:
           struct pollfd {
               int   fd;         // file descriptor 
               short events;     // requested events 
               short revents;    // returned events 
           };*/
        static struct pollfd pfd;
        int i;
        
        struct sigaction act;

        /* IO4 = gpio6 */
        pputs("/sys/class/gpio/export","6");
        pputs("/sys/class/gpio/gpio6/direction","in");
        
        /* gpio36= 1 = in */
        pputs("/sys/class/gpio/export","36");
        pputs("/sys/class/gpio/gpio36/direction","out");
        pputs("/sys/class/gpio/gpio36/value","1");
        
        /* gpio37 = in = no pull-up nor pull-down*/
        pputs("/sys/class/gpio/export","37");
        pputs("/sys/class/gpio/gpio37/direction","in");
        
        pputs("/sys/class/gpio/gpio6/edge","falling");
        
        if((pfd.fd=open("/sys/class/gpio/gpio6/value",O_RDONLY)) < 0)
        {
                perror("Opening gpio6:");
                return -1;
        }

        /* Clear old values */
        read(pfd.fd,&c,1);

        pfd.events=POLLPRI;

        puts("Waiting for interrupt. Press ^C to abort...");
        
        act.sa_handler=quit;
        /*SIGINT is the interrupt signal. The terminal sends it to the foreground process when the user presses ctrl-c. 
        The default behavior is to terminate the process, but it can be caught or ignored. The intention is to provide 
        a mechanism for an orderly, graceful shutdown. */
        sigaction(SIGINT,&act,NULL);
        
        /*SIGTERM is the termination signal. The default behavior is to terminate the process, but it also can be caught 
        or ignored. The intention is to kill the process, gracefully or not, but to first allow it a chance to cleanup.*/
        sigaction(SIGTERM,&act,NULL);

        for(i=0;run;i++)
        {
                /*poll() performs a similar task to select(2): it waits for one of a
                set of file descriptors to become ready to perform I/O.
                Specifying a negative value in timeout means an infinite timeout.  
                Specifying a timeout of zero causes poll() to return immediately, even 
                if no file descriptors are ready.*/
                //Argumentos em ordem: fds, número de fds, timeout;
                poll(&pfd,1,-1);

                //Move-se para o início do arquivo e lê um byte
                lseek(pfd.fd,0,SEEK_SET);        
                read(pfd.fd,&c,1);

                printf("%d %d\n",i,(int) (c == '1'));
        }
        
        close(pfd.fd);
        
        pputs("/sys/class/gpio/gpio6/edge","none");
        pputs("/sys/class/gpio/unexport","37");
        pputs("/sys/class/gpio/unexport","36");
        pputs("/sys/class/gpio/unexport","6");

        return 0;
}
