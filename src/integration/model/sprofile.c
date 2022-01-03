#include"main.h"
void integration()
{
for(int i=0; i<num;){

if(i==0) rk(x, y, tpaso, f);	//y1=rk(x0,y0)
else rk(x, y, tpaso, g);		//y(i+1)=rk(xi,yi) i \neq 0

//if(y[P]>=0)
if(*(y+P)==*(y+P))			//pressure is positive
{
saveSolution(&x,y,yaux,tpaso);		//xi->x(i+1),  yaux=y(i+1)
printSolution(x,y);				//x(i+1),y(i+1)
printCGS(x,y);
i++;
}

else{					//call the bisection method and then integrate in empty space
for (int m=0; m<N; m++) y[m]=yaux[m];
bisection(&x,y,yaux,tpaso);
printf("Radius\t\tMass\t\tEnergy\n");
printf("%.12E\t%.12E\t%.12E\n", x,y[MB],y[M]);
printSolution(x,y);
printCGS(x,y);
for(int j=0; j<num-i; j++){
rk(x, y, tpaso, h);
saveSolution(&x,y,yaux,tpaso);
printSolution(x,y);
printCGS(x,y);
}
i=num;
}
}
}
