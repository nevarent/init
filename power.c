// NOT USED YET

// POWER MANAGEMENT: POWEROFF, HALT, REBOOT...
#include "power.h"

int initReboot(void)
{
        sync();                                         // sync filesystems
        int result = reboot(LINUX_REBOOT_CMD_REBOOT);   // the reboot syscall
        if (result == -1)                               // if failed... 
        { 
                fprintf(stderr, "Reboot (REBOOT) failed\n"); 
        } 

        return result;
}

int initPoweroff(void)
{
        sync();                                          // sync
        int result = reboot(LINUX_REBOOT_CMD_POWER_OFF); // poweroff 
        if (result == -1) 
        { 
                fprintf(stderr, "Reboot (POWEROFF) failed\n"); 
        } 

        return result;
}

int initHalt(void)
{
        sync();                                         // sync
        int result = reboot(LINUX_REBOOT_CMD_HALT);     // halt
        if (result == -1)
        {
                fprintf(stderr, "Reboot (HALT) failed\n");
        }

        return result;
}
