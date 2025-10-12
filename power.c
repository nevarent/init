// POWER MANAGEMENT: POWEROFF, HALT, REBOOT...
#include "power.h"
#include <string.h>
#include <stdio.h>
#include <sys/reboot.h>
#include <unistd.h>
#include <sys/errno.h>
#include <asm-generic/errno-base.h>
#include "logger.h"

void initReboot(int sig)
{
	sync();						// sync filesystems
	int result = reboot(RB_AUTOBOOT);		// the restart syscall
	logger_checkResult(result, RB_AUTOBOOT);
}

void initPoweroff(int sig)
{
	sync();						 // sync
	int result = reboot(RB_POWER_OFF);		 // poweroff
	logger_checkResult(result, RB_POWER_OFF);
}

void initHalt(int sig)
{
	sync();						// sync
	int result = reboot(RB_HALT_SYSTEM);		// halt
	logger_checkResult(result, RB_HALT_SYSTEM);
}
