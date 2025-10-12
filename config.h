/* NOT USED IN INIT.C YET */
#ifndef CONFIG_H
#define CONFIG_H

char* rcfile = "/etc/rc.local";
char* conf = "/etc/rc.conf";

void config_load();
void config_checkExist();

#endif
