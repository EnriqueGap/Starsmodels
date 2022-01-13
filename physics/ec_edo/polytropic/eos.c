/* Polytropic Equation
P   = K*rhob^Gamma where rhob is rest mass density and Gamma= 1 + 1/n
rho = rhob + P/(Gamma-1) where rho is the energy density
This functions also calculates the  values of the radial function of metric
*/
#include"main.h"
double energy(double rhoc)
{
double energy = rhoc + (k*pow(rhoc,Gamma))/(Gamma-1);
}

void eos(double x, double y[], int i)
{
// If we know the density and we want the pressure and energy
if(i==P)
{
y[P] 	=k*pow(y[RHOB],Gamma);						//P
y[RHO]	=y[RHOB] + y[P]/(Gamma-1);				//rho
}
// If wen know the pressure and we want both densities
if(i==RHO)
{
if(x==0) y[A]=1;
else y[A]=sqrt(1/(1 - 2*y[M]/x));				//a
y[RHOB]=pow(y[P]/k,1/Gamma);					//rhob
y[RHO]=y[RHOB] + y[P]/(Gamma-1);				//rho
}
}

void checkEOS()
{
printf("It works");
}
