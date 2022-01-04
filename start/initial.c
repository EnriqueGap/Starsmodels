#include"main.h"
void initial()
{
xi=0, xf=4;				//Mesh
num=40000, tpaso=(xf-xi)/num;

nDensity=50000, stepDensity=(rhof-rhoi)/nDensity;

k=1, n=1.5, Gamma= 1.6666666666666666666666666667;
}
