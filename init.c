#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


        /* kill zombie processes */
void killZombies(int sig)                               // added int sig to shut the compiler up 
{
        while (waitpid(-1, NULL, WNOHANG) > 0);
}


int main()
{
        signal(SIGCHLD, killZombies);                   // trigger killZombies if init received SIGCHLD


                        /* start "service" - getty */
        pid_t servicePid = fork();
        if (servicePid < 0)
        {
                fprintf(stderr, "Fork failed!!!");
        }
        else if (servicePid == 0)
        {
                execl("/usr/bin/getty", "getty", "tty1", NULL);
        }

                        /* main loop - sleeper */
        while (1)
        {
                pause();                                // sleep until a signal received
        }



        return 0;                                       /* <-- unreachable | DON'T LET THIS HAPPEN */ 
}
