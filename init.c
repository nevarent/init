// WIP basic init system
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "power.h"
#include "service-management.h"
//#include "config.h"


	/* kill zombie processes */
void killZombies(int sig)				// added int sig to shut the compiler up 
{
	while (waitpid(-1, NULL, WNOHANG) > 0);
}


int main()
{
	signal(SIGCHLD, killZombies);			// trigger killZombies if init received SIGCHLD
	signal(SIGTERM, initPoweroff);			// poweroff if init received SIGTERM
	signal(SIGINT, initReboot);
	signal(SIGHUP, initHalt);

			/* start services */
	printf("[init] Starting services\n");

	startServices();

			/* main loop - sleeper */
	while (1)
	{
		pause();				// sleep until a signal received, repeat
	}



	return 0;					/* <-- unreachable, not happening */ 
}
