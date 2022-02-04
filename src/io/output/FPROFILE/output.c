#include "main.h"
//We export the correct values of stelar Mass and Radius for a specific density in cgs units and geometrical
void printSolution(double x, double y[])
{
    fprintf(data,"%.8E\t%.8E\t%.8E\t%.8E\n", rhoc,x,y[M],y[MB]);
}

void printCGS(double x, double y[])
{
    double cgs[N], cgsx, cgsrhoc;
    cgsx	  = convertDistance(x,CGS)/KM;
    cgs[RHOB] = convertDensity(y[RHOB],CGS);
    cgs[M]	  = convertMassEnergy(y[M],CGS);
    cgs[P]	  = convertPressure(y[P],CGS);
    cgs[RHO] = convertEnergy(y[RHO],CGS);
    cgs[MB]  = convertMass(y[MB],CGS)/SM;
    fprintf(datacgs,"%.8E\t%.8E\t%.8E\t%.8E\n", cgsrhoc,cgsx,cgs[M],cgs[MB]);
}
