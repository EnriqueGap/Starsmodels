#include"main.h"
void initial()
{
xi=0, xf=4;				//Mesh
num=20000, tpaso=(xf-xi)/num;

nDensity=1000, stepDensity=(rhof-rhoi)/nDensity;

k=1, n=1, Gamma= 1 + 1/n;
}
