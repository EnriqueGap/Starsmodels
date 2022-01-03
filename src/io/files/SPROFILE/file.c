#include"main.h"
void createFile()
{
data=fopen("profile.dat", "w");
datacgs=fopen("profilecgs.dat", "w");

time_t t = time(NULL);
struct tm tm = *localtime(&t);

fprintf(data,"%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
fprintf(datacgs,"%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

fprintf(data, "Radius\tBarionic density\tEnergy\tPressure\tEnergy density\tRest mass\tRadius metric\tTime metric\n");
fprintf(datacgs, "Radius\tBarionic density\tEnergy\tPressure\tEnergy density\tRest mass\n");
}
