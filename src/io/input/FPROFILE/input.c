#include "main.h"
void checkDensity()
{
int i;
double aux;

printf("To start, please enter the range of the barionic central densities of the family of stars.\n");

do{
printf("For values in cgs units enter 1, for values in gemetrized units enter 2.\n");
scanf("%d",&i);
}while(i!=1 && i!=2);

printf("Lower limit central densitity value: ");
scanf("%lf",&rhoi);

if(i==1){
aux=convertDensity(rhoi,GEO);
printf("Barionic central density in geometrized units: %.8Ex(10Km)^-2\n",aux);
rhoi=aux;
}
if(i==2){
aux=convertDensity(rhoi,CGS);
printf("Barionic central density in cgs units: %.8E\n",aux);
}

printf("Upper limit central densitity value: ");
scanf("%lf",&rhof);

if(i==1){
aux=convertDensity(rhof,GEO);
printf("Barionic central density in geometrized units: %.8Ex(10Km)^-2\n",aux);
rhof=aux;
}
if(i==2){
aux=convertDensity(rhof,CGS);
printf("Barionic central density in cgs units: %.8E\n",aux);
}
}

void checkParameters()
{
checkDensity();
initial();
}
