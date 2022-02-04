//To solve the ODE system we have three runge kutta methods

#include"main.h"
void rk( double x, double y[], double step, double (*f)(double x, double y[], int i) )
{
	double h=0.5*step,	
		t1[N], t2[N], t3[N],		//Auxiliares para calcular k2,k3 y k4
		k1[N], k2[N], k3[N],k4[N];	//Variables del Rk4
	int i;
	for (i=0;i<N;i++) t1[i]=y[i]+0.5*(k1[i]=step*(*f)(x, y, i));
	for (i=0;i<N;i++) t2[i]=y[i]+0.5*(k2[i]=step*(*f)(x+h, t1, i));
	for (i=0;i<N;i++) t3[i]=y[i]+    (k3[i]=step*(*f)(x+h, t2, i));
	for (i=0;i<N;i++) k4[i]=		step*(*f)(x+step, t3, i);
	for (i=0;i<N;i++) y[i]+=(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6.0;
}
