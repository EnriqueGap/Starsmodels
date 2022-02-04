#include"main.h"
void integration(){
	double paso;
	for (int a=0; a<=nDensity;){
		paso=tpaso;
		if(modelFPROFILE==TRUE){
			rhoc=rhoi+a*stepDensity;
		}
		else if(modelSPROFILE==TRUE){
			rhoc=rhoc;
		}
		x=xi;
		rho=energy(rhoc);
		ic(x,y,yaux);
		if(print==TRUE){
			printSolution(x,y);
			printCGS(x,y);
		}
		for(int i=0; i<=num;){
			if(i==0) rk(x,y,paso,f);
			else rk(x,y,paso,g);
			if(*(y+P)==*(y+P)){
				saveSolution(&x,y,yaux,paso);
				i++;
				if(print==TRUE){
					printSolution(x,y);
					printCGS(x,y);
				}
			}
			else{
				for(int m=0; m<N; m++) y[m]=yaux[m];
				bisection(&x,y,yaux,paso);
				printSolution(x,y);
				printCGS(x,y);
				if(modelSPROFILE==TRUE){
					printf("Radius\t\tMass\t\tEnergy\n");
            		printf("%.12E\t%.12E\t%.12E\n", x,y[MB],y[M]);
            		double auxx, auxmb, auxm;
            		auxx=x*CONV/KM;
            		auxmb=(y[MB]*CONV*pow(C,2)/G)/SM;
            		auxm=y[M]*CONV*pow(C,4)/G;
            		printf("%.12EKm\t%.12ESM\t%.12Eergs\n", auxx,auxmb,auxm);
					for(int j=0; j<num-i; j++){
						rk(x,y,paso,h);
						saveSolution(&x,y,yaux,paso);
						printSolution(x,y);
						printCGS(x,y);
					}
					i=num+1;
				}
				else if(modelFPROFILE==TRUE){
					i=num+1;
				}
				
			}
		}
		//exit of mesh in space, we reach de Nth place vía SPROFILE or stopping vía FPROFILE
		if(modelSPROFILE==TRUE){
			a=nDensity+1;
		}
		else if (modelFPROFILE==TRUE){
			if(a%50==0 && a>0) printf("\rIntegración exitosa de las primeras %d estrellas!!!!",a), fflush(stdout);
			a++;
		}
	}
	printf("\n");
}
