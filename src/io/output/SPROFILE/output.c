#include "main.h"
//We export the correct values with cgs units or geometrical and reescale the time metric function
void printSolution(double x, double y[])
{
double alfa=RES*y[ALPHA];
fprintf(data, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", x,y[RHOB],y[M],y[P],y[RHO],y[MB],alfa,y[A]);
}

void printDeb(double x,double y[])
{
fprintf(data, "%E\t%E\t%.16E\t%.16E\t%E\t%.16E\t%.16E\t%E\n", x,y[RHOB],y[M],y[P],y[RHO],y[MB],y[ALPHA],y[A]);
}

void printCGS(double x, double y[])
{
double cgs[N], cgsx;
cgsx	  = x*CONV/KM;
cgs[RHOB] = y[RHOB]*pow(CONV,-2)*pow(C,2)/G;
cgs[M]	  = y[M]*CONV*pow(C,4)/G;
cgs[P]	  = y[P]*pow(CONV,-2)*pow(C,4)/G;
cgs[RHO] = y[RHO]*pow(CONV,-2)*pow(C,4)/G;
cgs[MB]  = (y[MB]*CONV*pow(C,2)/G)/SM;
fprintf(datacgs, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", cgsx,cgs[RHOB],cgs[M],cgs[P],cgs[RHO],cgs[MB]);
}
