
#include <stdio.h>

#ifndef LOGGER_H
#define LOGGER_H

char* logger_dir = "/run/log/init/";
FILE* logger_File;

void logger_sync();
void logger_checkResult(int result, int opperation);


#endif
