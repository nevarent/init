// POWER MANAGEMENT: POWEROFF, HALT, REBOOT...
#ifndef POWER_H
#define POWER_H

#include <unistd.h>
#include <sys/reboot.h>

// these return 0 on success and -1 on error
void initReboot(int sig);
void initPoweroff(int sig);
void initHalt(int sig);

#endif
