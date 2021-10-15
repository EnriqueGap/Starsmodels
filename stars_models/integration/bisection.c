/* The star's pressures arises from Pc to 0. To set the star's boundary
we employ a bisection method where if the pressure is negative we back 
in the mesh and refine it to get better values as close to 0 as we set in
main.h library. These functions helps us to perform that. */
#include"main.h"
void bisection(double *x,double y[],double yaux[],double tpaso)
{
//Recieve the mesh values, the solution array and an auxiliary array
double r, r0, raux, tp;
r=*x;
tp=tpaso;
while (ERR<y[P]){
//Start the integrartion until the pressure is less or equal to our tolerance (ERR)
runge4(r, y, tp, g);
//If the pressure is still positive keep the values
if (y[P]==y[P]){
savey(&r,y,yaux,tp);
}
/*If the pressure is negative back in the mesh and recover the last values of the
array where the pressure was positive (y=yaux)*/
else{					
tp=tp*0.5;				
for (int m=0; m<N; m++) y[m]=yaux[m];
}
}
//At the end, set the position on the mesh on the star boundary calculated
*x=r;
printf("Radius\t\tMass\t\tEnergy\n");
printf("%.12E\t%.12E\t%.12E\n", r,y[MB],y[M]);
}
/* If P is positive then y has valid values and its must to be saved.
Later in the bisection method this values will be neccesary
*/
void savey(double *x,double y[],double yaux[],double tpaso)
{
double aux=*x+tpaso;
/*The runge kutta methods calculate the values of pressure, masses and
time metric function, to get the right values of densities and radial
metric function we need to calculate this with the ecuation of state */
ecdo(aux,y,RHO);
for (int i=0; i<N; i++) yaux[i]=y[i];
*x=aux;
}
//We export the correct values with cgs units or geometrical and reescale the time metric function
void printy(double x,double y[])
{
double alfa=RES*y[ALPHA];
fprintf(data, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", x,y[RHOB],y[M],y[P],y[RHO],y[MB],alfa,y[A]);
}

void printdeb(double x,double y[])
{
fprintf(data, "%E\t%E\t%.16E\t%.16E\t%E\t%.16E\t%.16E\t%E\n", x,y[RHOB],y[M],y[P],y[RHO],y[MB],y[ALPHA],y[A]);
}

void printcgs(double x,double y[])
{
double cgs[N], cgsx;
cgsx	  = x*CONV/KM;
cgs[RHOB] = y[RHOB]*pow(CONV,-2)*pow(C,2)/G;
cgs[M]	  = y[M]*CONV*pow(C,4)/G;
cgs[P]	  = y[P]*pow(CONV,-2)*pow(C,4)/G;
cgs[RHO] = y[RHO]*pow(CONV,-2)*pow(C,4)/G;
cgs[MB]  = (y[MB]*CONV*pow(C,2)/G)/MS;
fprintf(datacgs, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", cgsx,cgs[RHOB],cgs[M],cgs[P],cgs[RHO],cgs[MB]);
}
