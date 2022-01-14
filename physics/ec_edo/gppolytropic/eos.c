/*Generalized Piecewise Polytropic Equation https://arxiv.org/abs/2008.03342
P   = K*rhob^gamma + lambda 		where rhob is rest mass density
rho = (1+a)rhob + K/(gamma-1)rhob^gamma - lambda where rho is the energy density
This functions also calculates the  values of the radial function of metric*/

#include"main.h"
double energy(double rhoc)
{
    double auxrho, auxrhob;
    auxrhob=convertDensity(rhoc,CGS);

    if(gpp==CRUST){
        if(auxrhob>=crustparam->rho[4]){
            auxrho = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4])/(crustparam->gamma[4]-1) + (1+crustparam->a[4])*auxrhob - crustparam->lambda[4];
        }
        else if(auxrhob>=crustparam->rho[3]){
            auxrho = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3])/(crustparam->gamma[3]-1) + (1+crustparam->a[3])*auxrhob - crustparam->lambda[3];
        }
        else if(auxrhob>=crustparam->rho[2]){
            auxrho = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2])/(crustparam->gamma[2]-1) + (1+crustparam->a[2])*auxrhob - crustparam->lambda[2];
        }
        else if(auxrhob>=crustparam->rho[1]){
            auxrho = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1])/(crustparam->gamma[1]-1) + (1+crustparam->a[1])*auxrhob - crustparam->lambda[1];
        }
        else{
            auxrho = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0])/(crustparam->gamma[0]-1) + (1+crustparam->a[0])*auxrhob - crustparam->lambda[0];
        }
    }
    else if(gpp==NUCLEAR){
        if(auxrhob>=coreparam->rho[1]){
            auxrho = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*auxrhob - coreparam->lambda[2];
        }
        else if(auxrhob>=crustparam->rho[0]){
            auxrho = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1])/(coreparam->gamma[1]-1) + (1+coreparam->a[1])*auxrhob - coreparam->lambda[1];
        }
        else{
            auxrho = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0])/(coreparam->gamma[0]-1) + (1+coreparam->a[0])*auxrhob - coreparam->lambda[0];
        }
    }
    else if(gpp==NC){
        if(auxrhob>=coreparam->rho[1]){
            auxrho = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*auxrhob - coreparam->lambda[2];
        }
        else if(auxrhob>=crustparam->rho[0]){
            auxrho = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1])/(coreparam->gamma[1]-1) + (1+coreparam->a[1])*auxrhob - coreparam->lambda[1];
        }
        else if(auxrho<=coreparam->rho0){
            auxrho = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0])/(coreparam->gamma[0]-1) + (1+coreparam->a[0])*auxrhob - coreparam->lambda[0];
        }
        if(auxrhob>=crustparam->rho[4]){
            auxrho = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4])/(crustparam->gamma[4]-1) + (1+crustparam->a[4])*auxrhob - crustparam->lambda[4];
        }
        else if(auxrhob>=crustparam->rho[3]){
            auxrho = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3])/(crustparam->gamma[3]-1) + (1+crustparam->a[3])*auxrhob - crustparam->lambda[3];
        }
        else if(auxrhob>=crustparam->rho[2]){
            auxrho = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2])/(crustparam->gamma[2]-1) + (1+crustparam->a[2])*auxrhob - crustparam->lambda[2];
        }
        else if(auxrhob>=crustparam->rho[1]){
            auxrho = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1])/(crustparam->gamma[1]-1) + (1+crustparam->a[1])*auxrhob - crustparam->lambda[1];
        }
        else{
            auxrho = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0])/(crustparam->gamma[0]-1) + (1+crustparam->a[0])*auxrhob - crustparam->lambda[0];
        }
    }
    auxrho=auxrho*C*C;
    auxrho=convertEnergy(auxrho,GEO);
    return auxrho;
}

void eos(double x, double y[], int i)
{
    double auxrhob, auxpre, auxrho;

    // If we know the density and we want the pressure and energy
    if(i==P){
        auxrhob=y[RHOB];
        auxrhob=convertDensity(auxrhob,CGS);

        if(gpp==CRUST){
            if(auxrhob>=crustparam->rho[4]){
                auxrho = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4])/(crustparam->gamma[4]-1) + (1+crustparam->a[4])*auxrhob - crustparam->lambda[4];
                auxpre = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4]) + crustparam->lambda[4];
            }
            else if(auxrhob>=crustparam->rho[3]){
                auxrho = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3])/(crustparam->gamma[3]-1) + (1+crustparam->a[3])*auxrhob - crustparam->lambda[3];
                auxpre = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3]) + crustparam->lambda[3];
            }
            else if(auxrhob>=crustparam->rho[2]){
                auxrho = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2])/(crustparam->gamma[2]-1) + (1+crustparam->a[2])*auxrhob - crustparam->lambda[2];
                auxpre = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2]) + crustparam->lambda[2];
            }
            else if(auxrhob>=crustparam->rho[1]){
                auxrho = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1])/(crustparam->gamma[1]-1) + (1+crustparam->a[1])*auxrhob - crustparam->lambda[1];
                auxpre = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1]) + crustparam->lambda[1];
            }
            else{
                auxrho = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0])/(crustparam->gamma[0]-1) + (1+crustparam->a[0])*auxrhob - crustparam->lambda[0];
                auxpre = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0]) + crustparam->lambda[0];
            }
        }
        else if(gpp==NUCLEAR){
            if(auxrhob>=coreparam->rho[1]){
                auxrho = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*auxrhob - coreparam->lambda[2];
                auxpre = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2]) + coreparam->lambda[2];
            }
            else if(auxrhob>=crustparam->rho[0]){
                auxrho = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1])/(coreparam->gamma[1]-1) + (1+coreparam->a[1])*auxrhob - coreparam->lambda[1];
                auxpre = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1]) + coreparam->lambda[1];
            }
            else{
                auxrho = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0])/(coreparam->gamma[0]-1) + (1+coreparam->a[0])*auxrhob - coreparam->lambda[0];
                auxpre = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0]) + coreparam->lambda[0];
            }
        }
        else if(gpp==NC){
            if(auxrhob>=coreparam->rho[1]){
                auxrho = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*auxrhob - coreparam->lambda[2];
                auxpre = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2]) + coreparam->lambda[2];
            }
            else if(auxrhob>=crustparam->rho[0]){
                auxrho = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1])/(coreparam->gamma[1]-1) + (1+coreparam->a[1])*auxrhob - coreparam->lambda[1];
                auxpre = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1]) + coreparam->lambda[1];
            }
            else if(auxrhob<=coreparam->rho0){
                auxrho = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0])/(coreparam->gamma[0]-1) + (1+coreparam->a[0])*auxrhob - coreparam->lambda[0];
                auxpre = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0]) + coreparam->lambda[0];
            }
            if(auxrhob>=crustparam->rho[4]){
                auxrho = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4])/(crustparam->gamma[4]-1) + (1+crustparam->a[4])*auxrhob - crustparam->lambda[4];
                auxpre = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4]) + crustparam->lambda[4];
            }
            else if(auxrhob>=crustparam->rho[3]){
                auxrho = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3])/(crustparam->gamma[3]-1) + (1+crustparam->a[3])*auxrhob - crustparam->lambda[3];
                auxpre = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3]) + crustparam->lambda[3];
            }
            else if(auxrhob>=crustparam->rho[2]){
                auxrho = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2])/(crustparam->gamma[2]-1) + (1+crustparam->a[2])*auxrhob - crustparam->lambda[2];
                auxpre = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2]) + crustparam->lambda[2];
            }
            else if(auxrhob>=crustparam->rho[1]){
                auxrho = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1])/(crustparam->gamma[1]-1) + (1+crustparam->a[1])*auxrhob - crustparam->lambda[1];
                auxpre = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1]) + crustparam->lambda[1];
            }
            else{
                auxrho = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0])/(crustparam->gamma[0]-1) + (1+crustparam->a[0])*auxrhob - crustparam->lambda[0];
                auxpre = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0]) + crustparam->lambda[0];
            }
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
            if(auxpre>=crustparam->pre[4]){
                auxrhob = pow(((auxpre-crustparam->lambda[4])/crustparam->k[4]),1/crustparam->gamma[4]);
                auxrho = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4])/(crustparam->gamma[4]-1) + (1+crustparam->a[4])*auxrhob - crustparam->lambda[4];
            }
            else if(auxpre>=crustparam->pre[3]){
                auxrhob = pow(((auxpre-crustparam->lambda[3])/crustparam->k[3]),1/crustparam->gamma[3]);
                auxrho = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3])/(crustparam->gamma[3]-1) + (1+crustparam->a[3])*auxrhob - crustparam->lambda[3];
            }
            else if(auxpre>=crustparam->pre[2]){
                auxrhob = pow(((auxpre-crustparam->lambda[2])/crustparam->k[2]),1/crustparam->gamma[2]);
                auxrho = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2])/(crustparam->gamma[2]-1) + (1+crustparam->a[2])*auxrhob - crustparam->lambda[2];
            }
            else if(auxpre>=crustparam->pre[1]){
                auxrhob = pow(((auxpre-crustparam->lambda[1])/crustparam->k[1]),1/crustparam->gamma[1]);
                auxrho = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1])/(crustparam->gamma[1]-1) + (1+crustparam->a[1])*auxrhob - crustparam->lambda[1];
            }
            else{
                auxrhob = pow(((auxpre-crustparam->lambda[0])/crustparam->k[0]),1/crustparam->gamma[0]);
                auxrho = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0])/(crustparam->gamma[0]-1) + (1+crustparam->a[0])*auxrhob - crustparam->lambda[0];
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
            else{
                auxrhob = pow((auxpre-coreparam->lambda[0])/coreparam->k[0],1/coreparam->gamma[0]);
                auxrho = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0])/(coreparam->gamma[0]-1) + (1+coreparam->a[0])*auxrhob - coreparam->lambda[0];
            }
        }
        else if(gpp==NC){
            if(auxpre>=coreparam->pre[1]){
                auxrhob = pow((auxpre-coreparam->lambda[2])/coreparam->k[2],1/coreparam->gamma[2]);
                auxrho = coreparam->k[2]*pow(auxrhob,coreparam->gamma[2])/(coreparam->gamma[2]-1) + (1+coreparam->a[2])*auxrhob - coreparam->lambda[2];
            }
            else if(auxpre>=coreparam->pre[0]){
                auxrhob = pow((auxpre-coreparam->lambda[1])/coreparam->k[1],1/coreparam->gamma[1]);
                auxrho = coreparam->k[1]*pow(auxrhob,coreparam->gamma[1])/(coreparam->gamma[1]-1) + (1+coreparam->a[1])*auxrhob - coreparam->lambda[1];
            }
            else if(auxpre>=coreparam->pre0){
                auxrhob = pow((auxpre-coreparam->lambda[0])/coreparam->k[0],1/coreparam->gamma[0]);
                auxrho = coreparam->k[0]*pow(auxrhob,coreparam->gamma[0])/(coreparam->gamma[0]-1) + (1+coreparam->a[0])*auxrhob - coreparam->lambda[0];
            }
            if(auxpre>=crustparam->pre[4]){
                auxrhob = pow(((auxpre-crustparam->lambda[4])/crustparam->k[4]),1/crustparam->gamma[4]);
                auxrho = crustparam->k[4]*pow(auxrhob,crustparam->gamma[4])/(crustparam->gamma[4]-1) + (1+crustparam->a[4])*auxrhob - crustparam->lambda[4];
            }
            else if(auxpre>=crustparam->pre[3]){
                auxrhob = pow(((auxpre-crustparam->lambda[3])/crustparam->k[3]),1/crustparam->gamma[3]);
                auxrho = crustparam->k[3]*pow(auxrhob,crustparam->gamma[3])/(crustparam->gamma[3]-1) + (1+crustparam->a[3])*auxrhob - crustparam->lambda[3];
            }
            else if(auxpre>=crustparam->pre[2]){
                auxrhob = pow(((auxpre-crustparam->lambda[2])/crustparam->k[2]),1/crustparam->gamma[2]);
                auxrho = crustparam->k[2]*pow(auxrhob,crustparam->gamma[2])/(crustparam->gamma[2]-1) + (1+crustparam->a[2])*auxrhob - crustparam->lambda[2];
            }
            else if(auxpre>=crustparam->pre[1]){
                auxrhob = pow(((auxpre-crustparam->lambda[1])/crustparam->k[1]),1/crustparam->gamma[1]);
                auxrho = crustparam->k[1]*pow(auxrhob,crustparam->gamma[1])/(crustparam->gamma[1]-1) + (1+crustparam->a[1])*auxrhob - crustparam->lambda[1];
            }
            else{
                auxrhob = pow(((auxpre-crustparam->lambda[0])/crustparam->k[0]),1/crustparam->gamma[0]);
                auxrho = crustparam->k[0]*pow(auxrhob,crustparam->gamma[0])/(crustparam->gamma[0]-1) + (1+crustparam->a[0])*auxrhob - crustparam->lambda[0];
            }
        }        
        auxrho=auxrho*C*C;
        y[RHO]=convertEnergy(auxrho,GEO);
        y[RHOB]=convertDensity(auxrhob,GEO);
    }
}