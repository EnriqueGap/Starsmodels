#include"main.h"
void integration()
{
double paso;
for (int a=0; a<nDensity; a++){

paso=tpaso;
x=xi;

rhoc=rhoi + a*stepDensity;
rho=energy(rhoc);
ic(x,y,yaux);
rk(x, y, paso, f);
saveSolution(&x,y,yaux,paso);

bisection(&x,y,yaux,paso);

printSolution(x,y);
printCGS(x,y);
//fprintf(data,"%.8E\t%.8E\t%.8E\t%.8E\n", rhoc,x,y[M],y[MB]);

if(a%50==0) printf("Integración exitosa de las primeras %d estrellas!!!!\n",a);
}
}
