/*Generalized Piecewise Polytropic Equation https://arxiv.org/abs/2008.03342
P   = K*rhob^gamma + lambda 		where rhob is rest mass density
rho = (1+a)rhob + K/(gamma-1)rhob^gamma - lambda where rho is the energy density
This functions also calculates the  values of the radial function of metric
*/
#include"main.h"
double energy(double rhoc)
{
    double energy, aux;
    aux=convertDensity(rhoc,CGS);

    if(gpp==CRUST){
        energy = sly4crust.k[4]*pow(aux,sly4crust.gamma[4])/(sly4crust.gamma[4]-1) + (1+sly4crust.a[4])*aux - sly4crust.lambda[4];
    }
    else if(gpp==NUCLEAR){
        energy = coreparam->k[2]*pow(aux,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*aux - coreparam->lambda[2];
    }
    energy=energy*C*C;
    energy=convertEnergy(energy,GEO);
    return energy;
}

void eos(double x, double y[], int i)
{
    double auxrhob, auxpre, auxrho;
    // If we know the density and we want the pressure and energy
    if(i==P){
        auxrhob=y[RHOB];
        auxrhob=convertDensity(auxrhob,CGS);

        if(gpp==CRUST){
            auxrho = sly4crust.k[4]*pow(auxrhob,sly4crust.gamma[4])/(sly4crust.gamma[4]-1) + (1+sly4crust.a[4])*auxrhob - sly4crust.lambda[4];
            auxpre = sly4crust.k[4]*pow(auxrhob,sly4crust.gamma[4]) + sly4crust.lambda[4];
        }

        else if(gpp==NUCLEAR){
        auxrho = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*auxrhob - coreparam->lambda[2];
        auxpre = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2]) + coreparam->lambda[2];
        }
    auxrho=auxrho*C*C;
    auxpre=auxpre*C*C;
    y[RHO]=convertEnergy(auxrho,GEO);
    y[P]=convertPressure(auxpre,GEO);
    }

    // If wen know the pressure and we want both densities
    if(i==RHO){
        if(x==0) y[A]=1;
        else y[A]=sqrt(1/(1 - 2*y[M]/x));				//a

        auxpre=y[P];
        auxpre=convertPressure(auxpre,CGS);
        auxpre=auxpre/(C*C);

        if(gpp==CRUST){
            if(auxpre>=sly4crust.pre[4]){
                auxrhob = pow(((auxpre-sly4crust.lambda[4])/sly4crust.k[4]),1/sly4crust.gamma[4]);
                auxrho = sly4crust.k[4]*pow(auxrhob,sly4crust.gamma[4])/(sly4crust.gamma[4]-1) + (1+sly4crust.a[4])*auxrhob - sly4crust.lambda[4];
            }
            else if(auxpre>=sly4crust.pre[3]){
                auxrhob = pow(((auxpre-sly4crust.lambda[3])/sly4crust.k[3]),1/sly4crust.gamma[3]);
                auxrho = sly4crust.k[3]*pow(auxrhob,sly4crust.gamma[3])/(sly4crust.gamma[3]-1) + (1+sly4crust.a[3])*auxrhob - sly4crust.lambda[3];
            }
            else if(auxpre>=sly4crust.pre[2]){
                auxrhob = pow(((auxpre-sly4crust.lambda[2])/sly4crust.k[2]),1/sly4crust.gamma[2]);
                auxrho = sly4crust.k[2]*pow(auxrhob,sly4crust.gamma[2])/(sly4crust.gamma[2]-1) + (1+sly4crust.a[2])*auxrhob - sly4crust.lambda[2];
            }
            else if(auxpre>=sly4crust.pre[1]){
                auxrhob = pow(((auxpre-sly4crust.lambda[1])/sly4crust.k[1]),1/sly4crust.gamma[1]);
                auxrho = sly4crust.k[1]*pow(auxrhob,sly4crust.gamma[1])/(sly4crust.gamma[1]-1) + (1+sly4crust.a[1])*auxrhob - sly4crust.lambda[1];
            }
            else if(auxpre>=sly4crust.pre[0]){
                auxrhob = pow(((auxpre-sly4crust.lambda[0])/sly4crust.k[0]),1/sly4crust.gamma[0]);
                auxrho = sly4crust.k[0]*pow(auxrhob,sly4crust.gamma[0])/(sly4crust.gamma[0]-1) + (1+sly4crust.a[0])*auxrhob - sly4crust.lambda[0];
            }
        }

        else if(gpp==NUCLEAR){
            if(auxpre>=coreparam->pre[1]){
                auxrhob = pow((auxpre-coreparam->lambda[2])/coreparam->k[2],1/coreparam->gamma[2]);
                auxrho = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*auxrhob - coreparam->lambda[2];
            }
            else if(auxpre>=coreparam->pre[0]){
                auxrhob = pow((auxpre-coreparam->lambda[1])/coreparam->k[1],1/coreparam->gamma[1]);
                auxrho = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1])/(coreparam->gamma[1]-1) + (1+coreparam->a[1])*auxrhob - coreparam->lambda[1];
            }
            else if(auxpre>=coreparam->rho0){
                auxrhob = pow((auxpre-coreparam->lambda[0])/coreparam->k[0],1/coreparam->gamma[0]);
                auxrho = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0])/(coreparam->gamma[0]-1) + (1+coreparam->a[0])*auxrhob - coreparam->lambda[0];
            }
        }
        auxrho=auxrho*C*C;
        y[RHO]=convertEnergy(auxrho,GEO);
        y[RHOB]=convertDensity(auxrhob,GEO);
    }
}
