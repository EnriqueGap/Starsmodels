#include"main.h"
void createFile()
{
data=fopen("family.dat", "w");
datacgs=fopen("familycgs.dat", "w");

time_t t = time(NULL);
struct tm tm = *localtime(&t);

fprintf(data,"%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
fprintf(data,"Density\tRadius\tEnergy\tRest mass\n");

fprintf(datacgs,"%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
fprintf(datacgs,"Density\tRadius\tEnergy\tRest mass\n");
}
