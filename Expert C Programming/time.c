#include "time.h"
#include "stdio.h"

int main(int argc, char** argv) {
    time_t max_time = 0xFFFFFFFF;
    time_t current_time;
    time(&current_time);
    printf("Max time %s", ctime(&max_time));
    printf("Current time is %s", ctime(&current_time));
    time_t diff = difftime(max_time, current_time);
    diff = diff/60;
    int minutes = diff % 60;
    diff = diff/60;
    int hours = diff % 24;
    diff = diff/24;
    //printf("Years %d, Months %d, Days %d, Hours %d, Minutes %d");
}

