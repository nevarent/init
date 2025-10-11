// POWER MANAGEMENT: POWEROFF, HALT, REBOOT...
#include "power.h"
#include <stdio.h>
#include <sys/reboot.h>
#include <unistd.h>


void initReboot(int sig)
{
	sync();						// sync filesystems
	int result = reboot(RB_AUTOBOOT);		// the restart syscall
        if (result == -1)				// if failed... 
        { 
                fprintf(stderr, "Reboot (REBOOT) failed\n"); 
        } 
}

void initPoweroff(int sig)
{
	sync();						 // sync
	int result = reboot(RB_POWER_OFF);		 // poweroff 
        if (result == -1) 
        { 
                fprintf(stderr, "Reboot (POWEROFF) failed\n"); 
        } 
}

void initHalt(int sig)
{
	sync();						// sync
	int result = reboot(RB_HALT_SYSTEM);		// halt
	if (result == -1)
	{
		fprintf(stderr, "Reboot (HALT) failed\n");
	}
}
