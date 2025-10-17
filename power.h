// POWER MANAGEMENT: POWEROFF, HALT, REBOOT...
#ifndef POWER_H
#define POWER_H

#include <unistd.h>
#include <sys/reboot.h>

void initReboot(int sig);
void initPoweroff(int sig);
void initHalt(int sig);

#endif
