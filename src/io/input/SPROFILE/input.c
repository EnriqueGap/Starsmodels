#include "main.h"
//We export the correct values with cgs units or geometrical and reescale the time metric function

void checkDensity()
{
int i;
double aux;

printf("To start, please enter the value of the barionic central density of the star.\n");

do{
printf("For values in cgs units enter 1, for values in gemetrized units enter 2.\n");
scanf("%d",&i);
}while(i!=1 && i!=2);

printf("Densitity value: ");
scanf("%lf",&rhoc);

if(i==1){
aux=convertDensity(rhoc,GEO);
printf("Barionic central density in geometrized units: %.8Ex(10Km)^-2\n",aux);
rhoc=aux;
}
if(i==2){
aux=convertDensity(rhoc,CGS);
printf("Barionic central density in cgs units: %.8E\n",aux);
}
}

void checkParameters()
{
initial();
x=xi;
checkDensity();
rho=energy(rhoc);
ic(x,y,yaux);				//y0
printSolution(x,y);				//x0,y0
printCGS(x,y);
}
