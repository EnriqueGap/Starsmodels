/* Polytropic Equation
P   = K*rhob^gamma where rhob is rest mass density and gamma= 1 + 1/n
rho = rhob + P/(gamma-1) where rho is the energy density
This functions also calculates the  values of the radial function of metric
*/
#include"main.h"
double energy(double rhoc)
{
double k=1, n=1, gamma= 1.6666666666666667;
double energy = rhoc + (k*pow(rhoc,gamma))/(gamma-1);
}

void eos(double x, double y[], int i)
{
double k=1, n=1, gamma= 1 + 1/n;
// If we know the density and we want the pressure and energy
if(i==P){
y[P] 	=k*pow(y[RHOB],gamma);					//P
y[RHO]	=y[RHOB] + y[P]/(gamma-1);				//rho
}
// If wen know the pressure and we want both densities
if(i==RHO){
if(x==0) y[A]=1;
else y[A]=sqrt(1/(1 - 2*y[M]/x));				//a
y[RHOB]=pow(y[P]/k,1/gamma);					//rhob
y[RHO]=y[RHOB] + y[P]/(gamma-1);				//rho
}
}
