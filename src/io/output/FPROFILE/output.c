#include "main.h"
//We export the correct values of stelar Mass and Radius for a specific density in cgs units and geometrical
void printSolution(double x, double y[])
{
fprintf(data,"%.8E\t%.8E\t%.8E\t%.8E\n", rhoc,x,y[M],y[MB]);
}

void printCGS(double x, double y[])
{
double cgs[N], cgsx, cgsrhoc;
cgsx	  = x*CONV/KM;
cgs[RHOB] = y[RHOB]*pow(CONV,-2)*pow(C,2)/G;
cgs[M]	  = y[M]*CONV*pow(C,4)/G;
cgs[P]	  = y[P]*pow(CONV,-2)*pow(C,4)/G;
cgs[RHO] = y[RHO]*pow(CONV,-2)*pow(C,4)/G;
cgs[MB]  = (y[MB]*CONV*pow(C,2)/G)/SM;
cgsrhoc=convertDensity(rhoc,CGS);
fprintf(datacgs,"%.8E\t%.8E\t%.8E\t%.8E\n", cgsrhoc,cgsx,cgs[M],cgs[MB]);
}
