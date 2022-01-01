/*This module create stars profiles as a function of its central density,
and export the final radius and massof each star*/
#include"main.h"
int main(){
data=fopen("mass.dat", "w");
data2=fopen("info.dat", "w");
fprintf(data,"Density\tRadius\tEnergy\tRest mass\n");
double x,	 			
	y[N], yaux[N], 		
	tpaso,			
	rhoi, rhof, rhom, n, m;
int a, b, c=32956, d=25;
//We create a mesh with different values of central density
rhoi=3.16941E-5, rhom=32.9564317, rhof=32.9564317;
n=(rhom-rhoi)/c;
m=(rhof-rhom)/d;

/*Then we do the same thing as in star_profile but here we don't have
a explicit mesh for the radius, we set a step and integrate. The integration
stops when we reach the star's boundary and export the final values. We refine this 
final values calling the bisection method. Then we reset the values and integrate 
a new star with a different central density */
for (a=0; a<c; a++){

tpaso=8E-3;
x=0;

rhoc=rhoi + a*n;
rho=energy(rhoc);
ic(x,y,yaux);
runge4(x, y, tpaso, f);
saveSolution(&x,y,yaux,tpaso);

bisection(&x,y,yaux,tpaso);

fprintf(data,"%.8E\t%.8E\t%.8E\t%.8E\n", rhoc,x,y[M],y[MB]);
printf("%.8E\t%.8E\t%.8E\t%.8E\n", rhoc,x,y[M],y[MB]);
}

for (b=0; b<d; b++){

tpaso=2E-4;
x=0;

rhoc=rhom + b*m;
rho=energy(rhoc);
ic(x,y,yaux);
runge4(x, y, tpaso, f);
saveSolution(&x,y,yaux,tpaso);

bisection(&x,y,yaux,tpaso);

fprintf(data,"%.8E\t%.8E\t%.8E\t%.8E\n", rhoc,x,y[M],y[MB]);
printf("%.8E\t%.8E\t%.8E\t%.8E\n", rhoc,x,y[M],y[MB]);
}
fclose(data);
}
