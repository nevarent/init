// POWER MANAGEMENT: POWEROFF, HALT, REBOOT...
#include "power.h"
#include <stdio.h>
#include <sys/reboot.h>
#include <unistd.h>
#include <signal.h>


static struct
{
	int sig;
	char *value;
} signals[] =
{
	{SIGTERM, "Poweroff"},
	{SIGINT, "Reboot"},
    	{SIGHUP, "Halt"},
	{0, NULL}
};

		/* result checker: check if reboot failed and tell if it did */
void resultChecker(int sig, int result)
{
	if (result != -1)			// return void if not failed
	{
		return;
	}
	for (int i = 0; signals[i].sig != 0; i++)	// actual magic here
	{
		if (signals[i].sig == sig)
		{
			fprintf(stderr, "Reboot (%s) failed!\n", signals[i].value);
			return;
		}
	}
}




void initReboot(int sig)
{
	sync();						// sync filesystems
	int result = reboot(RB_AUTOBOOT);		// the restart syscall
	resultChecker(sig, result);			// check for success 
}

void initPoweroff(int sig)
{
	sync();						 // sync
	int result = reboot(RB_POWER_OFF);		 // poweroff 
	resultChecker(sig, result);
}

void initHalt(int sig)
{
	sync();						// sync
	int result = reboot(RB_HALT_SYSTEM);		// halt
	resultChecker(sig, result);
}
