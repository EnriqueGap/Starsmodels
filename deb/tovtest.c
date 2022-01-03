#include"main.h"
int main(){
data=fopen("tovtest.dat", "w");
double y[N], r,
	ri,rf,tpaso,n,
	K,gamma,rho0b;

ri=0, rf=0.7;
tpaso=2E-4;
n=(rf-ri)/tpaso;

K=1.0, gamma= 2.0, rho0b=0.42;

r	= 0.0;
y[M]	= 0.0;
y[P]	= K*rho0b*rho0b;
y[RHO]	= rho0b + y[P]/(gamma-1);
y[BAR]  = rho0b;

fprintf(data, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", r,y[M],y[P],y[RHO],y[BAR]);		//r0,y0

runge4(r,y,tpaso,f);									//y1=rk4(x0,y0)

y[BAR] = sqrt(y[P]/K);
y[RHO]  = y[BAR] + y[P]/(gamma-1);
r	= r + tpaso;

fprintf(data, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", r,y[M],y[P],y[RHO],y[BAR]);		//r1,y1

for(int i=1; i<n; i++){

runge4(r,y,tpaso,g);									//y2=rk4(r1,y1)
y[BAR] = sqrt(y[P]/K);
y[RHO]  = y[BAR] + y[P]/(gamma-1);
r	= r + tpaso;
fprintf(data, "%.8E\t%.8E\t%.8E\t%.8E\t%.8E\n", r,y[M],y[P],y[RHO],y[BAR]);		//r2,y2
}
fclose(data);
}

double f(double x, double y[], int i)
{
if (i==M) return(4.0*PI*y[RHO]*x*x);
if (i==P) return(-(y[P]+y[RHO])*(4.0*PI*x*y[RHO]/3.0 + 4.0*PI*x*y[P])/(1 - 8.0*PI*y[RHO]*x*x/3.0));
if (i==RHO) return(0);
if (i==BAR) return(0);
}
double g(double x, double y[], int i)
{
if (i==M) return(4.0*PI*y[RHO]*x*x);
if (i==P) return(-(y[P]+y[RHO])*(y[M] + 4.0*PI*y[P]*x*x*x)/(x*(x - 2.0*y[M])));
if (i==RHO) return(0);
if (i==BAR) return(0);
}
