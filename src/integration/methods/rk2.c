#include"main.h"

void rk( double x, double y[], double step, double (*f)(double x, double y[], int i) )
{
double h=0.5*step,	
	t1[N],				//Auxiliares para calcular k2,k3 y k4
	k1[N], k2[N];			//Variables del Rk4
int i;
for (i=0;i<N;i++) t1[i]=y[i]+0.5*(k1[i]=step*(*f)(x, y, i));
for (i=0;i<N;i++) k2[i]=		step*(*f)(x+h, t1, i);

for (i=0;i<N;i++) y[i]+=k2[i];
}
