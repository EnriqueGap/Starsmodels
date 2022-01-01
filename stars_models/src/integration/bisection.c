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
saveSolution(&r,y,yaux,tp);
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
