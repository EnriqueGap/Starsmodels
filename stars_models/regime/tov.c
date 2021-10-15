/* These funcions models the newtonian equations of spherical and static stars inside and outside
The first one is called when we need to set the initial conditions valids for any star.
The second and third functions models the equations inside the star 
and the last one in the empty space. The second ecuation is necessary to avoid
the indetermination when x=0*/
#include"main.h"
void ci(double x, double y[], double yaux[])
{
y[M]	=0;					//m
y[ALPHA]=0.5;					//alfa
y[A]	=1;					//a
y[RHOB] =rhoc;					//rhob
y[MB]	=0;					//mb

ecdo(x,y,P);
for (int i=0;i++;i<N) yaux[i]=y[i];
}

double  f(double x, double y[], int i)
{
ecdo(x,y,RHO);
double aux = 4*PI*x*(rho/3 + y[P])/(1 - 8*PI*rho*pow(x,2)/3);
if (i==M) 	return(4*PI*y[RHO]*pow(x,2)); 	//dm/dr
if (i==P) 	return(-(y[RHO]+y[P])*aux);		//dP/dr
if (i==ALPHA) 	return(y[ALPHA]*aux);			//dalpha/dr
if (i==MB) 	return(4*PI*pow(x,2)*y[A]*y[RHOB]);	//dmb/dr
if (i==RHO)	return(0);
if (i==RHOB)	return(0);
if (i==A)	return(0);
}

double  g(double x, double y[], int i)
{
ecdo(x,y,RHO);
double aux = (y[M] + 4*PI*pow(x,3)*y[P])/(x*(x - 2*y[M]));
if (i==M) 	return(4*PI*y[RHO]*pow(x,2));		//dm/dr
if (i==P) 	return(-(y[RHO]+y[P])*aux);		//dP/dr
if (i==ALPHA) 	return(y[ALPHA]*aux);			//dalfa/dr				
if (i==MB) 	return(4*PI*pow(x,2)*y[A]*y[RHOB]);	//dmb/dr
if (i==RHO)	return(0);
if (i==RHOB)	return(0);
if (i==A)	return(0);
}

double  h(double x, double y[], int i)
{
ecdo(x,y,RHO);
double aux = y[M]/(x*(x - 2*y[M]));
if (i==M) 	return(0); 				//dm/dr
if (i==P) 	return(0);				//dP/dr
if (i==ALPHA) 	return(y[ALPHA]*aux);			//dalfa/dr	
if (i==MB) 	return(0);				//dmb/dr
if (i==RHO)	return(0);
if (i==RHOB)	return(0);
if (i==A)	return(0);
}
