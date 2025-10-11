// NOT USED YET

// POWER MANAGEMENT: POWEROFF, HALT, REBOOT...
#ifndef POWER_H
#define POWER_H

#include <unistd.h>
#include <sys/reboot.h>

// these return 0 on success and -1 on error
int initReboot(void);
int initPoweroff(void);
int initHalt(void);

#endif
