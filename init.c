// WIP basic init system
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "power.h"
#include "logger.h"

	/* kill zombie processes */
void killZombies(int sig)				// added int sig to shut the compiler up
{
	while (waitpid(-1, NULL, WNOHANG) > 0);
}


int main()
{
    logger_sync();
	signal(SIGCHLD, killZombies);			// trigger killZombies if init received SIGCHLD
	signal(SIGTERM, initPoweroff);			// poweroff if init received SIGTERM
							// TODO: reboot & halt


			/* start agetty */
		/* here should be the future service management stuff */
	printf("Starting agetty service\n");
	pid_t servicePid = fork();
	if (servicePid < 0)
        {
                fprintf(stderr, "Fork failed!!!\n");
        }
	else if (servicePid == 0)
	{
		execl("/usr/bin/agetty", "agetty", "tty1", NULL);	// i don't know how agetty works, later
	}

			/* main loop - sleeper */
	while (1)
	{
		pause();				// sleep until a signal received, repeat
	}



	return 0;					/* <-- unreachable, not happening */
}
