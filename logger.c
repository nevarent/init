#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "colors.h"

void logger_sync() {
    srand(time(NULL)*64/3);
    time_t timeN = time(NULL);
    if(timeN != -1) {
        struct tm *date = localtime(&timeN);
        char buffer[64];
        int random = rand() % 490523;

        logger_File = fopen(logger_dir+strftime(buffer, sizeof(buffer), "%Y-%m-%d", date) + random, "a+");
    }

}
void logger_checkResult(int result, int opperation) {
    if(result == -1){
        fprintf(stderr, COLOR_RED, "Opperation failed\n", COLOR_RESET);
        fprintf(logger_File, "Opperation(%s) failed\n", opperation);
    }
}
