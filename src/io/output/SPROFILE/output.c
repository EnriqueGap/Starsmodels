#include "main.h"
//We export the correct values with cgs units or geometrical and reescale the time metric function
void printSolution(double x, double y[])
{
double alfa=RES*y[ALPHA];
fprintf(data, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", x,y[RHOB],y[M],y[P],y[RHO],y[MB],alfa,y[A]);
}
void printCGS(double x, double y[])
{
double cgs[N], cgsx;
cgsx	  = convertDistance(x,CGS)/KM;
cgs[RHOB] = convertDensity(y[RHOB],CGS);
cgs[M]	  = convertMassEnergy(y[M],CGS);
cgs[P]	  = convertPressure(y[P],CGS);
cgs[RHO] = convertEnergy(y[RHO],CGS);
cgs[MB]  = convertMass(y[MB],CGS)/SM;
fprintf(datacgs, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", cgsx,cgs[RHOB],cgs[M],cgs[P],cgs[RHO],cgs[MB]);
}