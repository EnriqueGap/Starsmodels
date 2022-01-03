#include"main.h"
int main(){

double t, aux,					//variables de la derivada
	y[N], 					//y[0]=sol, y[1]=sol'
	tpaso, tpaso2;				//pasos de integracion
tpaso=0.04;
tpaso2=tpaso/2.0;

t=0.0;						//condiciones iniciales
aux=0.0;
y[0]=0.0;					//y(t=0)=0
y[1]=1.0;					//y'(t=0)=1
/////////////////////////////////////////////////////////////
//////////////Escritura de los datos para tpaso//////////////
///////////////////////////////////////////////////////////// 
data=fopen("mass.dat", "w");
for (int i=0; i*tpaso<=FINAL; i++)
{
   t=i*tpaso;					//ti
   runge2(t, y, tpaso,f);			//yi+1=rk4(yi, ti)
   aux=t+tpaso;				//ti+1
   fprintf(data, "%f\t%.10lf\t%.10lf\n", t,y[0],y[1]);
}
fclose(data);
/////////////////////////////////////////////////////////////
////////////Escritura de los datos para tpaso/2 /////////////
///////////////////////////////////////////////////////////// 
data2=fopen("mass2.dat", "w");
double t2, aux2, y2[N];
t2=0.0;
aux2=0.0;
y2[0]=0.0;
y2[1]=1.0;
data2=fopen("mass2.dat", "w");
for (int j=0; j*tpaso2<=FINAL; j++)
{
   t2=j*tpaso2;
   runge2(t2, y2, tpaso2,f);
   aux2=t2+tpaso2;
   fprintf(data2, "%f\t%.10lf\t%.10lf\n", t2,y2[0],y2[1]);
}
fclose(data2);
}
double  f(double x, double y[], int i)
{
if (i==0) return(y[1]);			//dy/dt=y'
if (i==1) return(y[1]*y[0]);			//dy'/dt=y'*y
}
/*double  f(double x, double y[], int i)
{
if (i==0) return(y[1]);			//dy/dt=y'
if (i==1) return(pow(y[0],3/2)+y[1]*x);	//dy'/dt= y^3/2 + xy'
}*/
