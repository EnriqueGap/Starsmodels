/* Create a star with a specific central density and export the the values of 
mass, energy, densities, pressure and metric functions as function of the radius. */
#include"main.h"
int main(){

data=fopen("profile.dat", "w");
datacgs=fopen("profilecgs.dat", "w");
fprintf(data, "Radius\tBarionic density\tEnergy\tPressure\tEnergy density\tRest mass\tRadius metric\tTime metric\n");
fprintf(datacgs, "Radius\tBarionic density\tEnergy\tPressure\tEnergy density\tRest mass\n");
double x, 				//radius variable
	y[N], yaux[N], 		//Solution array
	xi, xf, tpaso, num;		//mesh parameters
	
x=xi=0, xf=4;				//Mesh
num=4000, tpaso=(xf-xi)/num;

rhoc=0.42;
rho=energy(rhoc);

ci(x,y,yaux);				//y0
printy(x,y);				//x0,y0
//printcgs(x,y);

for(int i=0; i<num;){

if(i==0) runge4(x, y, tpaso, f);	//y1=rk(x0,y0)
else runge4(x, y, tpaso, g);		//y(i+1)=rk(xi,yi) i \neq 0

if(y[P]==y[P]){			//pressure is positive
savey(&x,y,yaux,tpaso);		//xi->x(i+1),  yaux=y(i+1)
printy(x,y);				//x(i+1),y(i+1)
//printcgs(x,y);
i++;
}

else{					//call the bisection method and then integrate in empty space
for (int m=0; m<N; m++) y[m]=yaux[m];
//bisection(&x,y,yaux,tpaso);
//printy(x,y);
//printcgs(x,y);
for(int j=0; j<num-i; j++){
runge4(x, y, tpaso, h);
savey(&x,y,yaux,tpaso);
printy(x,y);
//printcgs(x,y);
}
i=num;
}

}
fclose(data);
fclose(datacgs);
}
